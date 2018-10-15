#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
  if(argc < 2){
    fprintf(stdout, "There is no student registered yet.\n");
    return 0;
  }

  fprintf(stdout, "Registered %s. ¥n", argv[1]);

}
