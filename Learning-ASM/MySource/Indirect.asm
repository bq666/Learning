.model small

.data

  C EQU 4
  
    arr DB 15h,12h,13h,25h,11h,37h
  
  var DB 15h
  


.code

main PROC
    
    MOV AX,@data
    MOV DS,AX
    
    ;indirect
    MOV AL, [0]
    MOV AL, [1+1]
    MOV AL, [1]+1
    MOV AL, 1+[1] ;wrong !!!
    
    MOV AL,2[arr]  ;<--- third element of array
    
    MOV AH,[C]
    
    ;indirect indexed
    
    MOV SI,3
    MOV AL,SI[arr]
    
    MOV SI,2
    
    MOV BL,[SI]
    
    LEA DI,arr
    
    MOV BH,[DI]
    
    ;indirect based
    
    MOV BX,3
    
    MOV CL,[BX]
    
    LEA BX,var
    
    MOV CH,[BX]
    
    
    ;bp
    
    main ENDP

END