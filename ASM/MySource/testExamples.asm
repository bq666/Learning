
.model small

.data


.code

main PROC
      
      ;see if MSB and LSB are 0
      
      MOV AL,00101010b
      
      TEST AL,10000001b
       
       ;ZF=1 => MSB and LSB are 0
       ;else they are not   
      
      ;see if bl is negative 
      
      MOV BL,-3
      
      TEST BL,0ffh
      
      ;SF=1 => bl is negative 
      
      MOV AL, 5
      NOT AL
      INC AL
      
      MOV AH, 2
      MOV DL, 'a'
      INT 21h
      
    
      
    
    
    
    main ENDP

END