	.text
	.globl	_unlink
	.weak	unlink
	.globl	_seterrno
unlink:
_unlink:svc	#1,#87		
	blt0	r1,_seterrno
	ret

