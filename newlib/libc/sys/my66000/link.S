	.text
	.globl	_link
	.weak	link
	.globl	_seterrno
link:
_link:	svc	#2,#86		
	blt0	r1,_seterrno
	ret

