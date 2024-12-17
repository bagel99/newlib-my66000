	.text
	.globl	_sbrk
	.weak	sbrk
	.globl	_end
sbrk:
_sbrk:	mov	r2,r1	
	ldd	r3,[ip,__curbrk]
	beq0	r1,9f
	add	r1,r2,r3	; curbrk + incr
	call	__brk
	cmp	r4,r1,#-1
	beq	r4,__seterror
	add	r1,r2,r3	; curbrk + incr
	std	r1,[ip,__curbrk]
9:	mov	r1,r3		; curbrk
	ret	
		
	.data
__curbrk: .dword	_end

