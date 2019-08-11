section .text
global summation
summation:
  mov eax, edi  ; edi = arg0
  mov ebx, eax
  mov eax, 0
  mov ecx, 0
  myLoop:
    cmp ebx, ecx
    je end
    inc ecx
    add eax, ecx
    jmp myLoop
  end:
  ret           ; return result