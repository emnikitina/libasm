			global	_ft_strcmp

			section	.text

_ft_strcmp:	xor	rcx, rcx
			xor	al, al
			xor	bl, bl

again:		mov	al, byte[rdi + rcx]
			mov	bl, byte[rsi + rcx]
			cmp	al, bl
			jne	return		
			cmp	byte[rdi + rcx], 0
			je	return
			cmp	byte[rsi + rcx], 0
			je	return
			inc	rcx
			jmp	again

return:		sub	rax, rbx
			ret
