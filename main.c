#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  char *s1 = (char *)calloc(256, sizeof(char));
  int fd = open("a.ppm", O_CREAT | O_WRONLY, 0644);
  sprintf(s1, "P3\n 500 500 255\n");
  write(fd, s1, strlen(s1));

  //int randfd = open("/dev/random", O_RDONLY);
  //unsigned int *r = (int *)calloc(1, sizeof(int));
  int i=0, z=0, j=0, r=0;

  for(i=0;i<500*500;i++){
    r = (i + 1000) % 256;
    sprintf(s1, "%u ", r);
    write(fd, s1, strlen(s1));
    //write(fd, "\n", strlen("\n"));
  }
  close(fd);
  free(s1);
  //free(r);
  //close(randfd);
  return 0;
}
