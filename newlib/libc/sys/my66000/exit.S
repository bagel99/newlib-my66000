	.text
	.globl	_exit
_exit:
	svc	#0,#60
	.word	0		; halt?

