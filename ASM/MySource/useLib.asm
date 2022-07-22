;include /home/bq666/Download/someLib.inc
INCLUDE lib/myLib.INC
.model small 
.data

.code
main PROC
    lab: putc 'a'
         putc 48
         MOV AL, 'g'
         putc AL
         
         MOV AX, 5
         PUSH AX
         CALL double 
         
         HLT
     main ENDP
END
