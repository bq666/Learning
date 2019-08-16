
.model small

.data

  C EQU 12          ;constant
  
  var DB 15h

.code

main PROC
    
    MOV AX,@data
    MOV DS,AX
    
    ;Immediate
    MOV AL,5
    
    MOV AH,C
    
    MOV var,2
    
    ;Registerg
    XCHG AL,AH
    
    MOV BL,CL
    
    ;direct
    MOV var,5
    MOV AL, var
    XCHG BL, var
    
    
    ;MOV CL,[BX]
    
    ;LEA AL,var              
    
    ;MOV BL,var
    
    main ENDP

END
