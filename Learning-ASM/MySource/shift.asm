.model small
.data 
    var DB 4
.code
main PROC
        MOV AX, @data
        MOV DS, AX
        
        MOV AL, -60
        SAR AL, 2
        
        
        
        MOV AL, 01010101b
        MOV CL, 2
        SHL AL, CL ;thesame SAL
        
        MOV AL, 5
        MOV CL ,1
        SHL AL, CL  ;2^cl 
        
        MOV AL, 00000001b
        MOV CX, 2
        
    ;for:SHL AL, 1
     ;   JNC lp
    ;    INC BL
     ;lp:LOOP for
        
        MOV AL, 10000010b
        SHR AL, 1   ;not the same than SAR adding 1 when end 1; SHR not !
        MOV AL, 10000010b
        SAR AL, 1
        ;with minus us --->  SAR <--- !!!
        
        
        
        
        MOV AX, 0
        
        main ENDP
END
