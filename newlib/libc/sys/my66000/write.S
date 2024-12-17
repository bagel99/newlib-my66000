	.text
	.globl	_write
	.weak	write
	.globl	_seterrno
write:
_write:	svc	#3,#1
	blt0	r1,_seterrno
	ret

