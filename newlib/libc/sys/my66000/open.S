	.text
	.globl	_open
	.weak	open
	.globl	_seterrno
open:
_open:	svc	#3,#2
	blt0	r1,_seterrno
	ret

