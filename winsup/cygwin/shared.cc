/* shared.cc: shared data area support.

   Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

#include "winsup.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>
#include "pinfo.h"
#include "security.h"
#include "fhandler.h"
#include "path.h"
#include "dtable.h"
#include "cygerrno.h"
#include "cygheap.h"
#include "heap.h"
#include "shared_info_magic.h"
#include "registry.h"
#include "cygwin_version.h"

shared_info NO_COPY *cygwin_shared = NULL;
mount_info NO_COPY *mount_table = NULL;
HANDLE cygwin_mount_h;

char * __stdcall
shared_name (const char *str, int num)
{
  static NO_COPY char buf[MAX_PATH] = {0};
  extern bool _cygwin_testing;

  __small_sprintf (buf, "%s.%s.%d", cygwin_version.shared_id, str, num);
  if (!_cygwin_testing)
    strcat (buf, cygwin_version.dll_build_date);
  return buf;
}

void * __stdcall
open_shared (const char *name, int n, HANDLE &shared_h, DWORD size, void *addr)
{
  void *shared;

  if (!shared_h)
    {
      char *mapname;
      if (!name)
	mapname = NULL;
      else
	{
	  mapname = shared_name (name, n);
	  shared_h = OpenFileMappingA (FILE_MAP_READ | FILE_MAP_WRITE,
				       TRUE, mapname);
	}
      if (!shared_h &&
	  !(shared_h = CreateFileMappingA (INVALID_HANDLE_VALUE,
					   &sec_all,
					   PAGE_READWRITE,
					   0,
					   size,
					   mapname)))
	api_fatal ("CreateFileMappingA, %E.  Terminating.");
    }

  shared = (shared_info *) MapViewOfFileEx (shared_h,
				       FILE_MAP_READ | FILE_MAP_WRITE,
				       0, 0, 0, addr);

  if (!shared)
    {
      /* Probably win95, so try without specifying the address.  */
      shared = (shared_info *) MapViewOfFileEx (shared_h,
				       FILE_MAP_READ|FILE_MAP_WRITE,
				       0, 0, 0, 0);
    }

  if (!shared)
    api_fatal ("MapViewOfFileEx '%s'(%p), %E.  Terminating.", name, shared_h);

  debug_printf ("name %s, shared %p (wanted %p), h %p", name, shared, addr, shared_h);

  /* FIXME: I couldn't find anywhere in the documentation a note about
     whether the memory is initialized to zero.  The code assumes it does
     and since this part seems to be working, we'll leave it as is.  */
  return shared;
}

void
shared_info::initialize ()
{
  if (version)
    {
      if (version != SHARED_VERSION_MAGIC)
	multiple_cygwin_problem ("shared", version, SHARED_VERSION);
      else if (cb != SHARED_INFO_CB)
	multiple_cygwin_problem ("shared size", cb, SHARED_INFO_CB);
      return;
    }

  /* Initialize the queue of deleted files.  */
  delqueue.init ();

  /* Initialize tty table.  */
  tty.init ();
  version = SHARED_VERSION_MAGIC;
  cb = sizeof (*this);
  if (cb != SHARED_INFO_CB)
    system_printf ("size of shared memory region changed from %u to %u",
		   SHARED_INFO_CB, cb);
}

void __stdcall
memory_init ()
{
  /* Initialize general shared memory */
  HANDLE shared_h = cygheap ? cygheap->shared_h : NULL;
  cygwin_shared = (shared_info *) open_shared ("shared",
					       CYGWIN_VERSION_SHARED_DATA,
					       shared_h,
					       sizeof (*cygwin_shared),
					       cygwin_shared_address);

  cygwin_shared->initialize ();

  /* Allocate memory for the per-user mount table */
  char user_name[UNLEN + 1];
  DWORD user_name_len = UNLEN + 1;

  if (!GetUserName (user_name, &user_name_len))
    strcpy (user_name, "unknown");

  /* Initialize the Cygwin heap, if necessary */
  if (!cygheap)
    {
      cygheap_init ();
      cygheap->user.set_name (user_name);
    }

  debug_init ();

  cygheap->shared_h = shared_h;
  ProtectHandleINH (cygheap->shared_h);

  heap_init ();
  mount_table = (mount_info *) open_shared (user_name, MOUNT_VERSION,
					    cygwin_mount_h,
					    sizeof (mount_info), 0);
  debug_printf ("opening mount table for '%s' at %p", cygheap->user.name (),
		mount_table_address);
  ProtectHandleINH (cygwin_mount_h);
  debug_printf ("mount table version %x at %p", mount_table->version, mount_table);

  /* Initialize the Cygwin per-user mount table, if necessary */
  if (!mount_table->version)
    {
      mount_table->version = MOUNT_VERSION_MAGIC;
      debug_printf ("initializing mount table");
      mount_table->cb = sizeof (*mount_table);
      if (mount_table->cb != MOUNT_INFO_CB)
	system_printf ("size of mount table region changed from %u to %u",
		       MOUNT_INFO_CB, mount_table->cb);
      mount_table->init ();	/* Initialize the mount table.  */
    }
  else if (mount_table->version != MOUNT_VERSION_MAGIC)
    multiple_cygwin_problem ("mount", mount_table->version, MOUNT_VERSION);
  else if (mount_table->cb !=  MOUNT_INFO_CB)
    multiple_cygwin_problem ("mount table size", mount_table->cb, MOUNT_INFO_CB);

}

void __stdcall
shared_terminate ()
{
  if (cygheap->shared_h)
    ForceCloseHandle (cygheap->shared_h);
  if (cygwin_mount_h)
    ForceCloseHandle (cygwin_mount_h);
}

unsigned
shared_info::heap_chunk_size ()
{
  if (!heap_chunk_in_mb)
    {
      /* Fetch misc. registry entries.  */

      reg_key reg (KEY_READ, NULL);

      /* Note that reserving a huge amount of heap space does not result in
      the use of swap since we are not committing it. */
      /* FIXME: We should not be restricted to a fixed size heap no matter
      what the fixed size is. */

      heap_chunk_in_mb = reg.get_int ("heap_chunk_in_mb", 256);
      if (heap_chunk_in_mb < 4)
	{
	  heap_chunk_in_mb = 4;
	  reg.set_int ("heap_chunk_in_mb", heap_chunk_in_mb);
	}
    }

  return heap_chunk_in_mb << 20;
}
