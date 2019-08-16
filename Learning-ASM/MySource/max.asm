
.model small

.data
    var1 db 1

    array DW 12h,5h,15h,3h,17h
 
 max DW ?
 
.code
 
main PROC
    
         MOV AX,@data
         MOV DS,AX
         
         LEA SI,array
         MOV AX,[SI]
         
         MOV CX,5
         
     for:ADD SI,2
         CMP [SI],AX
         JB lp
         MOV AX,[SI]
      lp:LOOP for
         
         MOV max,AX
    
    main ENDP

END