	.text
	.globl	__brk
	.weak	brk
brk:
__brk:	svc	#1,#12
	blt0	r1,_seterror
	ret

