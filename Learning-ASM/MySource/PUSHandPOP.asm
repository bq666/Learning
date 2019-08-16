.model small
.stack 100h
.data

.code
main PROC
   ;PUSHF puts the flags register in the stack 
   ;POPF puts the value pointed with sp in the flags register; move pointer 
   
   ;POPF
   MOV AX, 9
   MOV BX, 6
   PUSH AX
   PUSH BX
   POPF
   PUSHF
   PUSHF
   PUSHF
   PUSHF
   POP AX
   POP BX
   
   XCHG AX, BX
   POPF
   
   
   MOV AX, 0ffFFh
   PUSH AX
   PUSH AX
   PUSH AX
   PUSH AX
   PUSH AX
   PUSH AX
   POP DX
   POP DX
   POP DX 
   POP DX
   POP DX 
   POP DX
   POP DX
   POP DX
   POP DX
   POP DX 
   POP DX
   POP DX 
   POP DX
   POP DX 
    
    
    
    
    
    
   MOV AX, 0 
    main ENDP
END