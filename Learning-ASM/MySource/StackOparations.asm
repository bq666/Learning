
.model small

.stack 100h

.data


.code

main PROC
    
    MOV AX,1215h
    MOV BX,1719h
    MOV CX,2123h
    PUSH AX
    PUSH BX
    PUSH CX
    MOV BP,SP
    MOV DX,[BP+2]
    
    
    
    MOV AX,5
    MOV BX,7
    MOV CX,9
    
    PUSH AX
    PUSH BX
    PUSH CX
    
    MOV BP,SP  ;BP always the same as SP
    MOV DL,[BP+4]
    MOV [BP+2], 66h
    
    MOV AX, 0

    main ENDP

END