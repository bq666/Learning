;global _start
;
;_start:
;	mov eax, 1
;	mov ebx, 42
;	int 0x80
;	;syscall

global _start

section .data
	msg db "Hello, world! dd", 0x0a
	len equ $ - msg 

section .text
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 0x80
	mov eax, 1
	mov ebx, 0
	int 0x80
