
.model

.data

msg DB 'enter a binary number',10,13,'$'


.code

main PROC
         MOV AX,@data
         MOV DS,AX   
         
         ;print msg
         MOV AH,9
         LEA DX,msg
         INT 21h
         
         ;reset bl
         XOR BL,BL
         
         ;while loop
         
   while:;user input
         MOV AH,1
         INT 21h
         
         ;if user input is CR then go to endw
         CMP AL,13
         JE endw
         
         ;convert from ASCII to bin
         SUB AL,48
         
         ;shift left bl
         SHL BL,1
         
         ;insert bin value to bl's LSB 
         OR BL,AL
         
         JMP while
         
         ;convert from bin to ASCII
    endw:ADD BL,48
        
         ;CR
         MOV AH,2
         MOV DL,10
         INT 21h
         MOV DL,13
         INT 21h
         
         ;print it 
         MOV AH,2
         MOV DL,BL
         INT 21h
          
          
         ;the rest to be continued 
         
         MOV AH,4ch
         INT 21h
         
         main ENDP

END
    
    