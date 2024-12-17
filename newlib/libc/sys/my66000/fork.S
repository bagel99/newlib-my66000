	.text
	.globl	_fork
	.weak	fork
	.globl	_seterror
fork:
_fork:	svc	#0,#57
	ble0	r1,_seterror
	ret

