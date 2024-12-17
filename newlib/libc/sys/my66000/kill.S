	.text
	.globl	_kill
	.weak	kill
	.globl	_seterrno
kill:
_kill:	svc	#2,#62		
	blt0	r1,_seterrno
	ret

