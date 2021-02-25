#include <stdlib.h>

#define BYTE_SIZE (128*1024*1024)

int main()
{
  volatile char *a;
  int i;

  a = (volatile char *)malloc(BYTE_SIZE);

  for (i=0; i<BYTE_SIZE; i++) {
    a[i] = i;
  }
}
