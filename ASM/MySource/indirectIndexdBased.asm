
.model small

.data

 arr DB 15h,12h,2h,30h,55h,0FEh
 
     len=($-arr)
     
 var DB 25h    


.code

main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         ;indirect indexd based
         MOV SI,2
         MOV BX,2
         
         MOV AL,[BX+SI]
         
         MOV AL,[SI+BX]
         
         MOV AL,SI+[BX]
         
         MOV AL,SI[BX]
         
         MOV AL,BX+[SI]
         
         MOV AL,BX[SI]
         
         MOV AL,[SI]+BX
         
         MOV AL,[SI]BX
         
         MOV AL,[BX]+SI
         
         MOV AL,[BX]SI
         
         MOV AL,arr[BX][SI]
         
         MOV AL,[SI][BX]
    
    main ENDP

END