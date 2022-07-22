
.model small

.data

 array DB 'a','b','d','r'
 
 msg DB 'enter a letter',10,13,'$'
 
 msgyes DB 10,13,'yes$'
 
 msgno DB 10,13,'no$'
 
  

.code

main PROC
    
    
         MOV AX,@data
         MOV DS,AX
         
         ;prin msg
         MOV AH,9
         MOV DX,msg OFFSET
         INT 21h
         
         ;user input
         MOV AH,1
         INT 21h
                
         ;search operation       
         LEA SI,array
         
         MOV CX,5
         
     for:CMP [SI],AL
         JNE lp
         JMP yes
      lp:INC SI 
         LOOP for
         
         MOV AH,9
         LEA DX,msgno
         INT 21h
         JMP endf
         
     yes:MOV AH,9
         LEA DX,msgyes
         INT 21h
         
     endf:MOV AH,4ch
          INT 21h
          RET
    
    main ENDP

END