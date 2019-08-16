.model small

.data

 arr DB 12,15,8,? ;4 dup(5)
     
     DB 2,18,3,16 ;4 dup(?)
     
     DB 13,12,15,20
     
     len=($-arr)
     


.code

main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         MOV CX,len

    main ENDP

END 