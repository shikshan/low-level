/*
Program to demonstrate the behaviour of volatile keyword.

Compile using (-c flag states compile or assemble but don't link and -o provides output file):
gcc -g -c src/volatile.c -o out/volatile.o

Then inspect the output using:
objdump -d -M intel -S out/volatile.o

For details of various flags for above commands see:
https://stackoverflow.com/questions/1289881/using-gcc-to-produce-readable-assembly/1289907#1289907
For DWORD PTR explanation see:
https://stackoverflow.com/a/2987916/529174
*/

#include <stdio.h>

int main(void)
{
  int ordinary = 0;
  volatile int vol = 9;

  ordinary++;
  vol++;

  ordinary++;
  vol++;
}

/* relevant part of the output.
Value of vol variable is fetched from main memory every time before incrementing but not for ordinary variable

#include <stdio.h>

int main(void)
{
   0:   55                      push   rbp
   1:   48 89 e5                mov    rbp,rsp
  int ordinary = 0;
   4:   c7 45 fc 00 00 00 00    mov    DWORD PTR [rbp-0x4],0x0
  volatile int vol = 9;
   b:   c7 45 f8 09 00 00 00    mov    DWORD PTR [rbp-0x8],0x9

  ordinary++;
  12:   83 45 fc 01             add    DWORD PTR [rbp-0x4],0x1
  vol++;
  16:   8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]
  19:   83 c0 01                add    eax,0x1
  1c:   89 45 f8                mov    DWORD PTR [rbp-0x8],eax

  ordinary++;
  1f:   83 45 fc 01             add    DWORD PTR [rbp-0x4],0x1
  vol++;
  23:   8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]
  26:   83 c0 01                add    eax,0x1
  29:   89 45 f8                mov    DWORD PTR [rbp-0x8],eax
  2c:   b8 00 00 00 00          mov    eax,0x0
}
  31:   5d                      pop    rbp
  32:   c3                      ret
*/
