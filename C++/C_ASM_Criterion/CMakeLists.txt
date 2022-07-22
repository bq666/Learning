cmake_minimum_required(VERSION 3.14)
project(C_ASM_Criterion C)

set(CMAKE_C_STANDARD 99)

add_executable(C_ASM_Criterion main.c tests.c my_strlen.asm sum.asm)

#todo my ------------------
target_link_libraries(C_ASM_Criterion criterion)
enable_language(ASM_NASM)


#set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
#set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> \
#    <FLAGS> -f ${CMAKE_ASM_NASM_OBJECT_FORMAT} -o <OBJECT> <SOURCE>")
#
#if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    set(CMAKE_ASM_NASM_FLAGS "${ASM_NASM_FLAGS} -g -Fdwarf")
#else()
#    set(CMAKE_ASM_NASM_FLAGS "${ASM_NASM_FLAGS}")
#endif()