global _start

section .text
_start:
	mov ebx, 1
	mov ecx, 6	
_loop:
	add ebx, ebx
	dec ecx
	cmp ecx, 0
	jg _loop
	mov eax, 1
	;mov ebx, ecx
	int 0x80
