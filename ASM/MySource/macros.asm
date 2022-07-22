.model small 
.data

.code
double MACRO num1
    local lab
    SHL num1, 1
    double ENDM

main PROC
    lab:MOV AL, 5
    double AL
    main ENDP
END
