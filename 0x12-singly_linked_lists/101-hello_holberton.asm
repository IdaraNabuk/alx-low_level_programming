section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0
    newline db 10, 0

section .text
    extern printf

global main
main:
    sub rsp, 8              ; Adjust stack pointer

    mov rdi, format         ; Format string
    mov rsi, hello          ; String to be printed
    xor eax, eax            ; Clear eax register
    call printf             ; Call printf function

    mov rdi, format         ; Format string for new line
    mov rsi, newline        ; New line string
    xor eax, eax            ; Clear eax register
    call printf             ; Call printf function

    add rsp, 8              ; Restore stack pointer

    xor eax, eax            ; Return 0
    ret
