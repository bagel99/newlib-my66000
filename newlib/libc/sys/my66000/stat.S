	.text
	.globl	_stat
	.weak	stat
	.globl	_seterrno
stat:
_stat:	svc	#2,#4		
	blt0	r1,_seterrno
	ret

