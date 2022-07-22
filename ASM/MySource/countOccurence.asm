
.model small

.data

  arr DB 5,3,2,5,6,7,5,5
         len=($-arr)   
  
  count DB ?

.code

main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         MOV CX,len
         
         MOV DL,0
         
         MOV SI,0
         
     for:CMP arr[SI],5
         JNE lp
         INC DL
      lp:INC SI
         LOOP for
         
         MOV count,DL
         

    main ENDP

END