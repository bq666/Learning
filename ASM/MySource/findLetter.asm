.model small
.data 
str1 DB 'this is a string',0
        len1=($-str1)
        
str2 DB 25 dup(?)

.code
main PROC
    MOV AX,@data
    MOV DS, AX
    
    MOV DL, str1 +1
    MOV AH,2
    INT 21h
    
    MOV CX, len1
    MOV SI, 0
    
    XOR AL,AL
    
for:MOV BL, str1[SI]
    CMP BL, 's'
    JNE lp
    INC AL
 lp:INC SI
    LOOP for
     
    main ENDP
END

    