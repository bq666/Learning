INCLUDE lib/emu8086.INC
.model small
.data

.code
main PROC
    print 'hello world'
    gotoxy 1,1
    putc '!'
    PUTC '6'
    CALL CLEAR_SCREEN
    CALL scan_num ;return in cx
    putc 10
    putc 13
    MOV AX,CX
    CALL print_num ;from ax
    
        
    MOV AX, 0

    main ENDP
DEFINE_CLEAR_SCREEN
define_scan_num
define_print_num
define_print_num_uns
END