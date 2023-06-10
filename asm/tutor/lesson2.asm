SECTION .data
msg db  'Hello friends!', 0Ah ; assign mg variable with your message

SECTION .text
global  _start

_start:
  mov edx, 14; number of bytes
  mov ecx, msg; mem address of message
  mov ebx, 1; write to STDOUT (1)
  mov eax, 4; invoke SYS_WRITE (opcode 4)
  int 80h

  mov ebx, 0 ; return 0 (errors) on exit
  mov eax, 1; invoke SYS_EXIT (opcode 1)
  int 80h ; request interrupt on libc using INT 80h
