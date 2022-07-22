
.model small

.data
  
 array DB 5 dup(?)
 
 msg1 DB 'enter 5 numbers',10,13,'$'
 
 msg2 DB 10,13,'you have entred:',10,13,'$'  


.code

main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         ;print msg1
         MOV AH,9
         LEA DX,msg1
         INT 21h
         
         ;user input
         MOV CX,5
         LEA DI,array
         
    for1:MOV AH,1
         INT 21h
         MOV [DI],AL
         INC DI
         
         ;carriage return
         MOV AH,2
         MOV DL,10
         INT 21h
         MOV DL,13
         INT 21h 
         
         LOOP for1
         
         ;output msg2
         
         MOV AH,9
         LEA DX,msg2
         INT 21h
         
         MOV CX,5
         LEA SI,array
         MOV AH,2
    
    for2:MOV DL,[SI]
         INT 21h
         
         INC SI
         
         ;carriage return
         MOV DL,10
         INT 21h
         MOV DL,13
         INT 21h 
         
         LOOP for2
    
         MOV AH,4ch
         INT 21h
         RET
    
    
    main ENDP

END