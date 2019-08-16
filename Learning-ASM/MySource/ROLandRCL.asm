.model small
.data

.code
main PROC
        MOV AL, 00001111b
        XOR BL, BL ; set 0 !
        MOV CX, 8
    for:ROL AL, 1
        JNC lp
        INC BL
     lp:loop for
    
    
        MOV AL, 11110000b
        MOV CL, 8
        ROL AL, CL
        
    
    
       MOV AL, 10001000b
       MOV CL, 1
       ROL AL, CL; left ROL and move to right side 1 if end 1 and set CF flag to 1
       ROL AL, CL
       ROL AL, CL
       RCL AL, CL;  left ROL and move to right side 1 if flag CF is 1 
       RCL AL, CL; 
       RCL AL, CL; 
       
       STC ; set flag CF 1 
       CLC ; set flag cf 0
            
    
    
    
   mov ax, 0 
    
    main ENDP
END