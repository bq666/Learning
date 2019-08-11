// Assembly code emitted by HLA compiler
// Version 2.16 build 4409 (prototype)
// HLA compiler written by Randall Hyde
// GAS compatible output


        .global    QuitMain__hla_
        .global    DfltExHndlr__hla_
        .global    _HLAMain
        .global    InstallSignals__hla_


  .text


        .extern    FILEIO_OPEN
        .extern    FILEIO_READ
        .extern    FILEIO_CLOSE
        .extern    _HLA_GET_EXCEPTIONPTREBP
        .extern    STDOUT_PUTU32
        .extern    STR_RINDEX2
        .extern    _HLA_PUSH_EXCEPTIONPTR
        .extern    STR_ALLOC1
        .extern    STR_EQ
        .extern    DefaultExceptionHandler__hla_
        .extern    abstract__hla_
        .extern    _HLA_SET_EXCEPTIONPTR
        .extern    HardwareException__hla_
        .extern    FILESYS_SIZENAME
        .extern    ARG_CMDLN
        .extern    excepts_install_signals
        .extern    BuildExcepts__hla_
        .extern    STDOUT_PUTS
        .extern    STR_DELETE3
        .extern    ARG_C
        .extern    ARG_V
        .extern    Raise__hla_
        .extern    shortDfltExcept__hla_


 .set _0852__strVar____hla_2131, _0852__strVar____hla_2133




  .text



        .type      InstallSignals__hla_,@function

InstallSignals__hla_:
        jmp        excepts_install_signals
End_InstallSignals__hla__2134:
  .size InstallSignals__hla_,End_InstallSignals__hla__2134-InstallSignals__hla_



        .type      DfltExHndlr__hla_,@function

DfltExHndlr__hla_:
        jmp        DefaultExceptionHandler__hla_
End_DfltExHndlr__hla__2135:
  .size DfltExHndlr__hla_,End_DfltExHndlr__hla__2135-DfltExHndlr__hla_





        .type      _HLAMain,@function

_HLAMain:
 .global _start
_start:
        movl       %esp, %eax 
_findEnvp_$$_:
        addl       $4, %eax 
        cmpl       $0, (%eax) 
        jne        _findEnvp_$$_
        addl       $4, %eax 
        mov        %eax, _envp__hla_ 
        lea        4(%esp), %eax 
        mov        %eax, _argv__hla_ 
        mov        (%esp), %eax 
        mov        %eax, _argc__hla_ 
        call       BuildExcepts__hla_
        pushl      $0 
        pushl      %ebp 
        pushl      %ebp 
        lea        4(%esp), %ebp 


        call       ARG_C
        cmpl       $3, %eax 
        je         false__hla_2136
        pushl      $str__hla_2137 
        call       STDOUT_PUTS
        call       ARG_C
        pushl      $str__hla_2138 
        call       STDOUT_PUTS
        pushl      %eax 
        call       STDOUT_PUTU32
        pushl      $str__hla_2139 
        call       STDOUT_PUTS
        call       ARG_CMDLN
        pushl      $str__hla_2140 
        call       STDOUT_PUTS
        pushl      %eax 
        call       STDOUT_PUTS
        pushl      $str__hla_2141 
        call       STDOUT_PUTS
        pushl      $str__hla_2139 
        call       STDOUT_PUTS
        mov        $1, %ebx 
        mov        $1, %eax 
        int        $128 
false__hla_2136:
        pushl      $1 
        call       ARG_V
        mov        %eax, filename1__hla_2121 
        pushl      $2 
        call       ARG_V
        mov        %eax, filename2__hla_2125 
        pushl      $str__hla_2142 
        call       STDOUT_PUTS
        pushl      filename1__hla_2121 
        call       STDOUT_PUTS
        pushl      $str__hla_2143 
        call       STDOUT_PUTS
        pushl      filename2__hla_2125 
        call       STDOUT_PUTS
        pushl      $str__hla_2144 
        call       STDOUT_PUTS
        pushl      $str__hla_2139 
        call       STDOUT_PUTS
        pushl      filename1__hla_2121 
        call       FILESYS_SIZENAME
        mov        %eax, filesize1__hla_2122 
        mov        %edx, filesize1__hla_2122+4 
        pushl      filename2__hla_2125 
        call       FILESYS_SIZENAME
        mov        %eax, filesize2__hla_2126 
        mov        %edx, filesize2__hla_2126+4 
        cmpl       $0, filesize1__hla_2122+4 
        je         _0861_skipAssertion___hla_2149
        pushl      _0862_msg___hla_2147 
        popl       AssertionStr 
        lea        str__hla_2150, %ecx 
        mov        $67, %edi 
        mov        $12, %eax 
        call       Raise__hla_

_0861_skipAssertion___hla_2149:
        cmpl       $0, filesize2__hla_2126+4 
        je         _0867_skipAssertion___hla_2155
        pushl      _0868_msg___hla_2153 
        popl       AssertionStr 
        lea        str__hla_2150, %ecx 
        mov        $67, %edi 
        mov        $12, %eax 
        call       Raise__hla_

_0867_skipAssertion___hla_2155:
        pushl      filesize1__hla_2122 
        call       STR_ALLOC1
        mov        %eax, buffer1__hla_2123 
        pushl      filesize2__hla_2126 
        call       STR_ALLOC1
        mov        %eax, buffer2__hla_2127 
        pushl      filename1__hla_2121 
        pushl      $0 
        call       FILEIO_OPEN
        mov        %eax, file1__hla_2120 
        pushl      file1__hla_2120 
        pushl      buffer1__hla_2123 
        pushl      filesize1__hla_2122 
        call       FILEIO_READ
        mov        buffer1__hla_2123, %ebx 
        mov        %eax, -4(%ebx) 
        mov        %eax, filesize1__hla_2122 
        pushl      file1__hla_2120 
        call       FILEIO_CLOSE
        pushl      filename2__hla_2125 
        pushl      $0 
        call       FILEIO_OPEN
        mov        %eax, file2__hla_2124 
        pushl      %eax 
        pushl      buffer2__hla_2127 
        pushl      filesize2__hla_2126 
        call       FILEIO_READ
        mov        buffer2__hla_2127, %ebx 
        mov        %eax, -4(%ebx) 
        mov        %eax, filesize2__hla_2126 
        pushl      file2__hla_2124 
        call       FILEIO_CLOSE
        pushl      buffer1__hla_2123 
        pushl      $str__hla_2156 
        call       STR_RINDEX2
        jnc        false__hla_2157
        pushl      buffer1__hla_2123 
        pushl      %eax 
        pushl      filesize1__hla_2122 
        call       STR_DELETE3
false__hla_2157:
        pushl      buffer2__hla_2127 
        pushl      $str__hla_2156 
        call       STR_RINDEX2
        jnc        false__hla_2158
        pushl      buffer2__hla_2127 
        pushl      %eax 
        pushl      filesize2__hla_2126 
        call       STR_DELETE3
false__hla_2158:
        pushl      buffer1__hla_2123 
        pushl      buffer2__hla_2127 
        call       STR_EQ
        jnc        false__hla_2159
        pushl      $str__hla_2160 
        call       STDOUT_PUTS
        mov        $0, %ebx 
        mov        $1, %eax 
        int        $128 
false__hla_2159:
        pushl      $str__hla_2161 
        call       STDOUT_PUTS
        mov        $1, %ebx 
        mov        $1, %eax 
        int        $128 
QuitMain__hla_:
        mov        $1, %eax 
        xorl       %ebx, %ebx 
        int        $128 
End__HLAMain_2162:
  .size _HLAMain,End__HLAMain_2162-_HLAMain









  .text


        .balign    (4)
len__hla_2137 :.long      0x25
        .long      0x25
str__hla_2137:

 .ascii "Usage: odCmp disasmFile1 disasmFile2"
 .byte 0xa
 .byte 0

 .byte 0
 .byte 0

        .balign    (4)
len__hla_2138 :.long      0xb
        .long      0xb
str__hla_2138:

 .ascii "Arguments: "
 .byte 0


        .balign    (4)
len__hla_2139 :.long      0x1
        .long      0x1
str__hla_2139:
 .byte 0xa
 .byte 0

 .byte 0
 .byte 0

        .balign    (4)
len__hla_2140 :.long      0x17
        .long      0x17
str__hla_2140:

 .ascii "Current command line: '"
 .byte 0


        .balign    (4)
len__hla_2141 :.long      0x1
        .long      0x1
str__hla_2141:

 .ascii "'"
 .byte 0

 .byte 0
 .byte 0

        .balign    (4)
len__hla_2142 :.long      0xa
        .long      0xa
str__hla_2142:

 .ascii "Comparing "
 .byte 0

 .byte 0

        .balign    (4)
len__hla_2143 :.long      0x5
        .long      0x5
str__hla_2143:

 .ascii " and "
 .byte 0

 .byte 0
 .byte 0

        .balign    (4)
len__hla_2144 :.long      0x3
        .long      0x3
str__hla_2144:

 .ascii "..."
 .byte 0


        .balign    (4)
len__hla_2148 :.long      0x2c
        .long      0x2c
str__hla_2148:

 .ascii "(type dword filesize1[4]) = 0 odCmp.hla (74)"
 .byte 0

 .byte 0
 .byte 0
 .byte 0

        .balign    (4)
len__hla_2150 :.long      0x20
        .long      0x20
str__hla_2150:

 .ascii "/usr/bin/hla/include/excepts.hhf"
 .byte 0

 .byte 0
 .byte 0
 .byte 0

        .balign    (4)
len__hla_2154 :.long      0x2c
        .long      0x2c
str__hla_2154:

 .ascii "(type dword filesize2[4]) = 0 odCmp.hla (75)"
 .byte 0

 .byte 0
 .byte 0
 .byte 0

        .balign    (4)
len__hla_2156 :.long      0x9
        .long      0x9
str__hla_2156:

 .ascii "endCode>:"
 .byte 0

 .byte 0
 .byte 0

        .balign    (4)
len__hla_2160 :.long      0x12
        .long      0x12
str__hla_2160:

 .ascii "Files compare OK"
 .byte 0xa
 .byte 0xa
 .byte 0

 .byte 0

        .balign    (4)
len__hla_2161 :.long      0x15
        .long      0x15
str__hla_2161:

 .ascii "Files do not match!"
 .byte 0xa
 .byte 0xa
 .byte 0

 .byte 0
 .byte 0
_0862_msg___hla_2147 :.long  str__hla_2148
_0868_msg___hla_2153 :.long  str__hla_2154




  .data

        .extern    ExceptionPtr__hla_
        .extern    AssertionStr
        .extern    MainPgmCoroutine__hla_
        .balign    (4)
file1__hla_2120 :.space     4
filename1__hla_2121 :.space     4
filesize1__hla_2122 :.space     8
buffer1__hla_2123 :.space     4
file2__hla_2124 :.space     4
filename2__hla_2125 :.space     4
filesize2__hla_2126 :.space     8
buffer2__hla_2127 :.space     4
DelFromHere__hla_2128 :.space     4
ReturnVal__hla_2129 :.long  0x0
line__hla_2132:
        .long      _0852__strVar____hla_2131
        .balign    (4)
        .long      0x100
        .long      0x0
_0852__strVar____hla_2133:
    .space 260,0


 .data
 .global _envp__hla_
 .global _argc__hla_
 .global _argv__hla_
_argc__hla_: .long 0
_argv__hla_: .long 0
_envp__hla_: .long 0





