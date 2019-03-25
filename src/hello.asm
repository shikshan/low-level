; nasm -f elf64 -o out/hello.o src/hello.asm && ld -o out/hello out/hello.o && ./out/hello
; making "size_t sys_write(unsigned int fd, const char * buf, size_t count)" call

section .data
  msg db    "Hello, world!"

section .text
  global    _start
_start:
  mov       rax, 1
  mov       rdi, 1
  mov       rsi, msg
  mov       rdx, 13
  syscall
  mov       rax, 60
  mov       rdi, 0
  syscall
