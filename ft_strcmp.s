section	.text
global	_ft_strcmp

_ft_strcmp:
			push	rdx
			push	rcx
			xor		rax,	rax

loop:
			cmp		byte [rdi], 0
			jz		return
			xor		rdx, rdx
			xor		rcx, rcx
			movsx	rdx, byte [rdi]
			movsx	rcx, byte [rsi]
			cmp		rdx, rcx
			jnz		return
			inc		rdi
			inc		rsi
			jmp		loop

return:
			mov		rax, rdx
			sub		rax, rcx
			pop		rcx
			pop		rdx
			ret
