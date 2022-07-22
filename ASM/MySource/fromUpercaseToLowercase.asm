.model small
.data
    char DB ?
    
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    
    ;read a char
    MOV AH, 1
    INT 21h
    MOV BL, AL
    
    ;verify if it is an uppercase char
    CMP AL, 65
    JB endf
    CMP AL, 90
    JA endf
    
    ;carriage return
    MOV AH, 2
    MOV DL, 10
    INT 21h
    MOV DL, 13
    INT 21h
    
    ;print and store the char
    MOV DL, BL
    ADD DL, 32
    MOV char, DL
    INT 21h
    
    
    endf:
    MOV AH, 4ch
    INT 21h
    
    
    
    
    main ENDP
END

