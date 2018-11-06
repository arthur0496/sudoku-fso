#include <stdio.h>
#include "verification.h"

int main(){
  int line,column;

  FILE *sudoku_file;
  sudoku_file = fopen("sudoku.txt","r");
  
  for(line = 0; line < 9; line++){
    for(column = 0; column <9; column++){
      fscanf(sudoku_file, "%d", &sudoku[line][column]);
    }
  }

  fclose(sudoku_file);
  
  int a = 1;
  pthread_t line_tid;
  pthread_attr_t line_attr;
  pthread_attr_init(&line_attr);
  pthread_create(&line_tid, &line_attr, verify_lines, NULL);

  pthread_join(line_tid,NULL);

  printf("%d\n", errors);


  return 0;
}
