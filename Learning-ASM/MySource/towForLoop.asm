
.model small

.data

 arr DB 1h,10h,2h,3h,30h
     
     DB 19h,20h,80h,13h,55h
     
     DB 13h,12h,15h,20h,68h
     
     len=($-arr)
     
 sum DB ?

.code

main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         ;al will contain the sum
         MOV AL,0
         MOV BX,0
         MOV SI,0
         
  while1:CMP BX,len
         JE endw1
         
         MOV SI,0
         while2:CMP SI,5   
                JE endw2
                
                ;if si=2 => column number 2 
                CMP SI,2
                JNE endif
                
                ADD AL,arr[BX][SI]
          endif:INC SI
                JMP while2
   
   endw2:
         ADD BX,SI
         
         JMP while1
         
   endw1:MOV sum,AL      

    
    
    
    
    
    main ENDP

END