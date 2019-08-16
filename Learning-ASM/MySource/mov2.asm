.model small
.code
main PROC
   MOV AX, 3
   MOV BX, 5
   MOV CX, 7
   
   MOV DX, AX
   MOV AX, CX
   MOV CX, BX
   MOV BX, DX 
    
    
    main ENDP
END


