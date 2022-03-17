			global	_ft_read

			section	.text
			extern	___error

_ft_read:	mov		rax, 0x2000003
			syscall
			jc		error
			ret

error:		push	r8
			mov		r8, rax
			call	___error
			mov		[rax], r8
			mov		rax, -1
			pop		r8
			ret
