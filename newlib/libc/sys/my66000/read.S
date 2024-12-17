	.text
	.globl	_read
	.weak	read
	.globl	_seterrno
read:
_read:	svc	#3,#0
	blt0	r1,_seterrno
	ret

