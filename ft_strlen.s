			global	_ft_strlen

			section .text

_ft_strlen:	mov		rax, 0
			mov		rcx, 0

again:		cmp		byte[rdi + rcx], 0
			jz		return
			inc		rcx
			jmp		again

return:
			mov		rax, rcx
			ret
