	.text
	.globl	_seterrno
_seterrno: add	r1,#0,-r1	; negate returned value
	stw	r1,[ip,errno]	; errno is 32-bit
	mov	r1,#-1
	ret

	.data
errno:	.word	0

