	.text
	.globl	_getpid
	.weak	getpid
	.globl	_seterrno
getpid:
_getpid:svc	#0,#39		
	blt0	r1,_seterrno
	ret

