	.text
	.globl	_fstat
	.weak	fstat
	.globl	_seterrno
fstat:
_fstat:	svc	#2,#5		
	blt0	r1,_seterrno
	ret

