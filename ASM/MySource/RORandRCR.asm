
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

ORG 100h

.model small
.data

.code
main PROC
    ;CLC
    MOV AL, 12
    RoR Al, 8
    
        MOV AL, 00001111b
        XOR BL, BL ; set 0 !
        MOV CX, 8
    for:ROR AL, 1
        JNC lp
        INC BL
     lp:LOOP for
    
    
        MOV AL, 11110000b
        MOV CL, 8
        ROR AL, CL
        
    
    
       MOV AL, 10001000b
       MOV CL, 1
       ROR AL, CL; 
       ROR AL, CL
       ROR AL, CL
       RCR AL, CL; 
       RCR AL, CL; 
       RCR AL, CL; 
       
       STC ; set flag CF 1 
       CLC ; set flag cf 0
            
    
    
    
   MOV AX, 0 
    
    main ENDP
END

RET




