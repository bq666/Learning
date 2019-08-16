.model small
.data
    marks2 DB 10 dup(5)
    marks DB 5,6,?,5,9,8
    var1 DB 7
    var2 DW 9
    var3 DB 1
    array DB 1, 2, 3, 4, 5, 6
    array DB 5 dup(?)
    msg1 DB 'enter 5 numbers', 10, 13, '$'
    msg2 DB 10,13, 'you have entred:', 10, 13, '$'
    
.code
main PROC
   MOV AX, @data
   MOV DS, AX
   
   ;print msg1
   MOV AH, 9
   LEA DX, msg1
   INT 21h
   
   ;user input
   MOV CX,5
   LEA DI, array
   
   for1:MOV AH, 1
        INT 21h
        MOV [DI], AL
        INC DI
        
        ;carriage return
        MOV AH,2
        MOV DL,10
        INT 21h
        MOV DL, 13
        INT 21h
        
        LOOP for1
        
        MOV AH, 9
        LEA DX, msg2
        
        
   
   
   
   
   MOV CX, 6
   MOV BX, 0
   MOV AX, 0
   
   
   LEA SI, array
   myLoop2:
    ADD AL, [SI]
    INC SI
    LOOP myLoop2 
   
    
   
   myLoop:
    MOV AL, marks2 + BX
    ;MOV marks + BX, 66
    MOV AL, marks2 + BX
    INC BX
    
    LOOP myLoop
   
   
    MOV AX, 0
   main ENDP
END