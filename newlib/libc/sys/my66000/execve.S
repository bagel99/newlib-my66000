	.text
	.globl	_execve
	.weak	execve
	.globl	_seterror
execve:
_execve:svc	#3,#59
	blt0	r1,_seterror
	ret

