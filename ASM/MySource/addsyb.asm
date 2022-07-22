.model small
.data 
    var1 DB 6
    var2 DB 7

.code
main PROC
    MOV AL, 6
    MOV BL, 7
    XCHG AL, BL
    
    MOV AL, 6
    MOV AH, 6
    ADD AL, AH
    MOV AH, 12
    sub al, ah
    
    
    
    
    
    main ENDP
END





