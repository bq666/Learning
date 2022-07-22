
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
         
         ;upper to lower 
         MOV AL, 'D'
         OR AL, 00100000b

         
         
         
         
    
    
    
    
         MOV AX, 0
         
    main ENDP

END