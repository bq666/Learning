.model small
.stack 100h
.data
    arr1 DW 1h, 12h, 5h, 16h, 3h, 70h, 55h
    len1=($-arr1)
    
    arr2 DW 6h, 66h, 9h, 99h, 4h, 44h
    len2=($-arr2)
    
.code
main PROC
        MOV AX, @data
        MOV DS, AX
        
        MOV AX, len1/2
        MOV AX, len2/2 
        
    
        MOV CX, len1/2
        MOV SI, 0
   for1:PUSH arr1[SI]
        ADD SI,2
        LOOP for1
        
        MOV CX,len1
        XOR SI,SI
   for2:POP arr1[SI]
        ADD SI, 2
        LOOP for2
        
    
        XOR AX, AX
    main ENDP
END
