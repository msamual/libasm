extern ___error
		
	section	.text
	global	_ft_read

_ft_read:
			mov		rax,	0x2000003
			syscall
			jc		return_error
			ret

return_error:
			push	r9
			push	rax
			pop		r9
			call	___error
			mov		[rax],	r9
			mov		rax,	-1
			pop		r9
			ret
