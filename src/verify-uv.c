/* 
Program to verify the workspace is set up properly.
Compile and run using:
gcc -Wall src/verify-uv.c -luv -Wl,-rpath,/usr/local/lib64 -o out/uv && ./out/uv
*/

#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

int main(void)
{
  uv_loop_t *loop = malloc(sizeof(uv_loop_t));
  uv_loop_init(loop);

  printf("Workspace set-up properly.\n");
  uv_run(loop, UV_RUN_DEFAULT);

  uv_loop_close(loop);
  free(loop);
  return 0;
}
