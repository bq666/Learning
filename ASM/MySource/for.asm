
.model small

.data



.code

main PROC
        
            MOV AH,2
            MOV DL,'a'
            
            MOV CX,26
            
        for:INT 21h
            INC DL
            LOOP for
            
            
            MOV AH,4ch
            INT 21h  
            RET
    
    
    
    
    main ENDP

END