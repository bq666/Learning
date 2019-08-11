global _start
_start:
	sub esp, 4
	mov [esp], byte 'H'
	mov [esp+1], byte 'e'
	mov [esp+2], byte 'H'
	mov [esp+3], byte 'e'
	mov [esp+4], byte 'S'
	mov [esp+5], byte 'Z'
	mov [esp+6], byte 10

	mov eax, 4  	;sys_write system call
	mov ebx, 1	;stdout file descriptor
	mov ecx, esp	;bytes to write
	mov edx, 8	;numbers of bytes to write
	int 0x80	;perform system call
	mov eax, 1	;sys_exit system call
	mov ebx, 0	;exit status is 0
	int 0x80	
