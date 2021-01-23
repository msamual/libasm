extern	___error
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy
	
	section	.text
	global	_ft_strdup

_ft_strdup:
			push	r9
			push	rsi
			call	_ft_strlen
			inc		rax
			push	rdi
			mov		rdi,	rax
			call	_malloc
			jz		return_error
			pop		r9
			mov		rdi,	rax
			mov		rsi,	r9
			call	_ft_strcpy
			mov		rdi, rax
			pop		rsi
			pop		r9
			ret

return_error:
			xor		rax,	rax
			pop		rsi
			pop		r9
			ret
