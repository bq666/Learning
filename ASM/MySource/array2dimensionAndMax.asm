.model small

.data

 arr1 DB 12,15,8,? ;4 dup(5)
     
     DW 2,18,3,16 ;4 dup(?)
     
     DB 13,12,15,20
     
     len1=($-arr)
     
 max DB ?

 arr DB 1h,10h,2h,3h
     
     DB 19h,20h,80h,13h
     
     DB 13h,12h,15h,20h
     
     DB 5h,2h,3h,17h
     
     len=($-arr)



.code

main PROC
    
         MOV AX,@data
         MOV DS,AX         
         
         MOV CX,len
         DEC CX
         
         MOV SI,0
         MOV AL,arr[SI]
         
     for:INC SI
         CMP arr[SI],AL
         JB lp
         MOV AL,arr[SI]
      lp:LOOP for
         
         MOV max,AL
         
         
         

    main ENDP

END 
