; todo 100% ok z asm
    [BITS 64]

    global my_strlen
    section .text

my_strlen:
    push rbp
    mov rbp, rsp
    xor rcx, rcx

loop:
    cmp BYTE [rdi + rcx], 0
    jz end
    inc rcx
    jmp loop

end:
    mov rax, rcx
    mov rsp, rbp
    leave
    ret