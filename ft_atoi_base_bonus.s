section	.text
global	_ft_atoi_base

_ft_atoi_base:
				push	rdx
				push	rcx
				mov		rdx,	0
				mov		rcx,	0
				mov		rax,	0

while_spaces:
				jmp		cmp_spaces
				space:
						inc	rdi
						jmp	while_spaces

positive:
				inc		rdi
				jmp		loops

negative:
				mov		rdx,	1
				inc		rdi
				jmp		loops

sign:
				cmp byte[rdi],	43
				je	positive
				cmp	byte[rdi],	45
				je	negative
				jmp	loops

cmp_spaces:
				cmp	byte[rdi],	32
				je	space
				cmp	byte[rdi],	7
				jl	sign
				cmp	byte[rdi],	13
				ja	sign
				jmp	space

cmp_is_digit:
				cmp	byte[rdi],	48
				jl	end
				cmp	byte[rdi],	57
				ja	end
				jmp	digit

loops:
				jmp	cmp_is_digit
				digit:
						mov	rax,		rsi
						mov	dl,		byte[rdi]
						mul	rcx
						mov	rcx,	rax
						add	rcx,	rdx
						sub	rcx,	48
						inc	rdi
						jmp	loops

end:
				mov		rax,	rcx
				pop		rcx
				pop		rdx
				ret