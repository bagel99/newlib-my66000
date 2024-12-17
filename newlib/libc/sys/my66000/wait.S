	.text
	.globl	_wait
	.globl	_waitpid
	.globl	_wait4
	.weak	wait
	.weak	waitpid
	.weak	wait4
	.globl	_seterrno
wait:
_wait:	mov	r2,r1
	mov	r1,#-1
	mov	r3,#0
waitpid:
_waitpid:mov	r4,#0
wait4:
_wait4:	svc	#4,#61		
	blt0	r1,_seterrno
	ret

