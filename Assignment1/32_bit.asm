section .data
msg db "Hello World", 0xa
len equ $-msg

section .text
global _start

_start:

mov eax, 4
mov ebx, 1
mov edx, len
mov ecx, msg
int 80h

mov ebx, 0
mov eax, 1
int 80h
