.model small
.data
    num1 DB 3
    num2 DB 6
    sum DB 0
    def DB 0
    
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    
    MOV AL, num1
    ADD AL, num2
    MOV sum, AL
    
    MOV AL, num1
    SUB AL, num2
    MOV def, AL
    
    MOV AL, 6
    INC AL
    INC num1
    
    DEC AL
    DEC num1
    DEC def
    
    NEG AL
    NEG num1
    NEG num2
    NEG def
    
    
    
    
    
    main ENDP
END