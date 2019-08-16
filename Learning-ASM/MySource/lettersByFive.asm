
.model small

.data

 userChar DB ?

.code

main PROC
    
           MOV AX,@data
           MOV DS,AX
           MOV BX, 65
           MOV CX, 0
           
        nextLetter:
           MOV AH, 2
           MOV DX, BX
           INC CX
           INC BX
           INT 21h
           
           MOV AH, 2
           MOV DX, 32
           INT 21h
           CMP CX, 5
           JE nextLine
           JMP nextLetter
           
           
        nextLine:
           ;carriage return
           MOV AH,2           
           MOV DL,10
           INT 21h
           MOV DL,13
           INT 21h
           
           MOV CX, 0
           CMP BX, 90
           JC nextLetter
           
      
            
            
      endf:MOV AH,4ch
           INT 21h
           RET 
    
    main ENDP

END