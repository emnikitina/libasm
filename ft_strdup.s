			global	_ft_strdup

			section .text
			extern	_malloc
			extern	_ft_strlen
			extern	_ft_strcpy

_ft_strdup:	push 	rdi
			call 	_ft_strlen
			mov		rdi, rax
			call 	_malloc
			test	rax, rax
			jz		error
			mov 	rdi, rax
			pop		rsi
			call	_ft_strcpy
			ret

error:		pop rsi
			ret
