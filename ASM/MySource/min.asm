
.model small

.data

 arr DB 12,15,11,2,5,3,15,1
        
        len1=($-arr)
        
 min DB ?


.code

main PROC
    
        MOV AX,@data
        MOV DS,AX
        
        ;cx = len - 1
        MOV CX,len1
        DEC CX
        
        ;lea si,arr
        MOV SI,arr OFFSET
        
        ;al will contain the min at the end
        MOV AL,[SI]
        
    for:INC SI
        CMP [SI],AL
        JA lp
        MOV AL,[SI]
     lp:LOOP for
            
    
        MOV min,AL
    
    
    
    main ENDP

END