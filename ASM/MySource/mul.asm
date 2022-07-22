INCLUDE /lib/emu8086.INC
.model small
.data

.code
main PROC
    MOV AL, 5
    MOV BL, 10
    MUL BL
    
    main ENDP
define_print_num
define_print_num_uns
END
