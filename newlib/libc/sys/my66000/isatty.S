	.text
	.globl	_isatty
	.weak	isatty
	.globl	_ioctl
isatty:
_isatty:mov	r2,#0x5401
	call	_ioctl
	pge0	r1,TF
	mov	r1,#1
	mov	r1,#0
	ret

