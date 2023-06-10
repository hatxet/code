SECTION .data
msg db  'Hello friends!', 0Ah ; assign mg variable with your message

SECTION .text
global  _start

_start:
  mov edx, 13; number of bytes
  mov ecx, msg; mem address of message
  mov ebx, 1; write to STDOUT (1)
  mov eax, 4; invoke SYS_WRITE (opcode 4)
  int 80h
