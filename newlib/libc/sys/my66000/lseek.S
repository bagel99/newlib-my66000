	.text
	.globl	_lseek
	.weak	lseek
	.globl	_seterrno
lseek:
_lseek:	svc	#2,#8
	blt0	r1,_seterrno
	ret

