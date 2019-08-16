;1.A = B - A
;2.A = -(A+1)
;3.C = A + B
;4.B = 3*B +7
;5.A = B - A -1

.model small
.data
    A DB 1
    B DB 2
    C DB 3
    
    
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    
    MOV AL, B
    SUB AL, A
    MOV A, AL
    
    INC A
    NEG A
    
    MOV AL, A
    ADD AL, B
    MOV C, AL
    
    MOV AL, b
    ADD AL, b
    ADD AL, b
    ADD AL, 7
    MOV b, AL
    
    MOV AL, b
    SUB AL, a
    DEC AL
    MOV a, AL
    
    
    
    
    
    
    
    main ENDP
END
    