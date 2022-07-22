INCLUDE /lib/emu8086.INC
.model small
.data

.code
main PROC
    MOV AX, 50
    MOV BL, 10
    MUL BL   ;and imul
    
    MOV AX, 50
    MOV BX, 8
    DIV BX     ;and idiv
    
    
    MOV AX, 0
    main ENDP
define_print_num
define_print_num_uns
END
