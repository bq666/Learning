.model small
.data

.code

main PROC
    MOV CX, 3
    for:MOV AX,CX  ;If (CX <> 0) then
        INC AX
        LOOP for
        
    MOV CX, 2
   for1:MOV AX, CX   ; loope or loopz  If (CX <> 0 AND ZF <> 1) then
        INC AX
        LOOPE for1
        
    MOV CX, 3
   for2:MOV AX, CX   ;  loopne or loopnz If (CX <> 0 AND ZF <> 0) then
        INC AX
        LOOPNE for2
    
    
    main ENDP
END