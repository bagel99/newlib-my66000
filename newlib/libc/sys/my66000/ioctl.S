	.text
	.global	_ioctl
	.weak	ioctl
ioctl:
_ioctl:	svc	#3,#16
	blt0	r1,_seterror
	ret

