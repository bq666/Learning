.model small

.data
C EQU 15
var1 DB 12
var2 DB ?


.code
main PROC
    MOV AX, @data
    MOV DS, AX    
    MOV var2, C
    MOV AL, var1
    MOV AH, var2
    MOV var1, AH
    MOV var2, AL
    
    
    
    
    main ENDP
END




