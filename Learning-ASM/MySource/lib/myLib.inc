;this macro prints an ascii char in the DOS
;@params char byte

putc MACRO char
    
    LOCAL lab
    
    lab:MOV AH,2
        MOV DL,char
        INT 21h
        
    putc ENDM


;this macro makes the addition operation of tow
;numbers

;@params num1,num2 word

;@return word

addition MACRO num1,num2
    
    MOV AX,num1
    MOV BX,num2
    ADD AX,BX
    PUSH AX
    
    addition ENDM


;this procedure doubles the number

;@params stack

;@params stack

double PROC near
    
    POP AX
    SHL AX,1
    PUSH AX
    
    RET
    double ENDP