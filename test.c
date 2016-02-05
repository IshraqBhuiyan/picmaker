#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  char *s1 = (char *)calloc(256, sizeof(char));
  int i = 0;
  int x = open("/dev/random", O_RDONLY);
  for(;i<5;i++){
    unsigned int *z = (int *)calloc(1, sizeof(int));
    read(x, z, sizeof(int));
    //unsigned int z = (unsigned int)s1;
    printf("%u\n", *z);

    //sleep(1);
  }
  close(x);
  return 0;
}
