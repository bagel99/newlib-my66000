	.text
	.globl	_close
	.weak	close
	.globl	_seterror
close:
_close:	svc	#1,#3
	blt0	r1,_seterror
	ret

