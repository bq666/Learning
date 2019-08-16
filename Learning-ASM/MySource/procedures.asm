.model small

.stack 100h

.data

 msg DB 'enter 5 numbers',10,13,'$'  

 input DB 5 dup(?)
 
 output DB 5 dup(?)


.code    

main PROC
    
    MOV AX,@data
    MOV DS,AX
    
    MOV AX, 1d
    MOV BX, 5d
    
    PUSH AX
    PUSH BX
    CALL ADDMY
    POP AX
        
    
    
    
    CALL user_req
    CALL user_input
    CALL test_even
    CALL user_output
    
    HLT          ; stop execute program 
    main ENDP

ADDMY PROC
    POP CX
    POP DX
    ADD CX, DX
    PUSH CX
    RET
    addmy ENDP


user_req PROC    ;near in this .code(default)          far from other .code 
    
    MOV AH,9
    LEA DX,msg
    INT 21h
    
    RET
    user_req ENDP
    
user_input PROC
    
    
        MOV SI,0
        MOV CX,5
        
        MOV AH,1
        
   for1:INT 21h
        CALL convert_dec
        MOV input[SI],AL
        INC SI
        LOOP for1
        
        RET
    user_input ENDP

convert_dec PROC
       
    SUB AL,48
       
    RET
    convert_dec ENDP

test_even PROC
    
        MOV SI,0
        XOR DI,DI
        MOV CX,5
        
   for2:TEST input[SI],1 ;00000001b
        JNZ lp
        MOV AL,input[SI]
        MOV output[DI],AL
        INC DI
        
     lp:INC SI
        LOOP for2
        
        RET
    test_even ENDP

user_output PROC
    
        MOV SI,0
        MOV AH,2
        MOV CX,5
        
        ;CR
   for3:MOV DL,10
        INT 21h
        MOV DL,13
        INT 21h 
                
        MOV DL,output[SI]        
        CALL convert_ascii
        INT 21h
        INC SI
        LOOP for3 
        
        RET
    user_output ENDP

convert_ascii PROC
       
    ADD DL,48
       
    RET
    convert_ascii ENDP


END
    
    