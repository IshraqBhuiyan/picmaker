#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  char *s1 = (char *)calloc(256, sizeof(char));
  int fd = open("a.ppm", O_CREAT | O_RDWR | O_APPEND, 0644);
  sprintf(s1, "P3\n500 500 256\n");
  write(fd, s1, strlen(s1));

  //int randfd = open("/dev/random", O_RDONLY);
  //unsigned int *r = (int *)calloc(1, sizeof(int));
  int i=0, z=0, j=0, r=0;

  for(;i<500;i++){
    for(z=0;z<500;z++){
      //read(randfd, r, sizeof(int));
      r = (i*z + 1000) % 256;
      sprintf(s1, "%u ", r);
      //printf("%s", s1);
      write(fd, s1, strlen(s1));
      //write(fd, " ", sizeof(" "));
    }
    //printf("\n");
    write(fd, "\n", sizeof("\n"));
  }
  close(fd);
  free(s1);
  //free(r);
  //close(randfd);
  return 0;
}
