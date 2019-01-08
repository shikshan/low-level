// Program to learn c and assembly interaction - Step 001 - empty function
// Compile using: gcc -g -c src/001.c -o out/001.o
// Peek inside using: objdump -dw -M intel -S out/001.o

int main(void)
{
  return 0;
}

/* relevant part of the output:
int main(void)
{
   0:   55                      push   rbp
   1:   48 89 e5                mov    rbp,rsp
  return 0;
   4:   b8 00 00 00 00          mov    eax,0x0
}
   9:   5d                      pop    rbp
   a:   c3                      ret
*/
