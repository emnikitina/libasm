			global	_ft_strcpy

			section	.text

_ft_strcpy:	xor	rcx, rcx
			xor	rax, rax
			xor	rdx, rdx

again:		cmp	byte[rsi + rcx], 0
			jz	return
			mov al, byte[rsi + rcx]
			mov byte[rdi + rcx], al
			inc rcx
			jmp again


return:		mov byte[rdi + rcx], 0
			mov	rax, rdi
			ret
