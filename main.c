#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char line[100];
  strcpy(line, argv[1]);
  strcat(line, " ");
  for(int i = 2; i < argc; i++) {
    strcat(line, argv[i]);
    strcat(line, " ");
  }
  // printf("%s\n", line);
  char ** args = parse_args(line);
  execvp(args[0], args);
  // printf("%d", argc);
  return 0;
}

char ** parse_args(char * line) {
  char ** args = calloc(32,sizeof(char*));
  size_t argnum = 0;
  char * token = "";
  while(line != NULL && argnum < 32){
    args[argnum] = calloc(1,32);
    token = strsep(&line, " ");
    strncpy(args[argnum], token, 32);
    argnum++;
  }
  return args;
}
