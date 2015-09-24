section .data
msg: db "Hello World", 0xa
len: equ $-msg

section .text
global _start

_start:

mov rax, 1
mov rbx, 1
mov rdi, len
mov rsi, msg
syscall

mov rbx, 0
mov rax, 60
syscall
