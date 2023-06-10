
section .data
  text db "Hello, Word!",10
section .text
  global _start

_start:
  mov rax, 1
  mov rdi, 2
  mov rsi, text
  mov rdx, 11
  syscall

  mov rax, 60
  mov rdi, 0
  syscall
  
