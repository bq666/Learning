
.model small

.data

 msg1 DB 'Please enter a lower case',10,13,'$'
 
 msg2 DB 10,13,'The upper case of your char is:$'
 
 msgerr DB 10,13,'This is not a lower case char$'


.code

main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         ;print msg1
         MOV AH,9
         LEA DX,msg1
         INT 21h
         
         ;user input
         MOV AH,1
         INT 21h
         MOV BL,AL
         
         ;verify user input 
         CMP AL,97
         JB err
         CMP AL,122
         JA err
         
         ;print result 
         MOV AH,9
         LEA DX,msg2
         INT 21h
         
         MOV AH,2
         MOV DL,BL
         SUB DL,32
         INT 21h
         JMP endf
         
     err:MOV AH,9
         LEA DX,msgerr
         INT 21h 
          
    endf:MOV AH,4ch
         INT 21h
         RET

    main ENDP

END