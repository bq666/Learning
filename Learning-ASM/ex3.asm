global _start

section .text
_start:
	mov ecx, 99
	mov ebx, 40
	mov eax, 1
	cmp ecx, 100
	jl skip
	mov ebx, 13
skip:
	int 0x80
	
