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

  pthread_t line_tid;
  pthread_attr_t line_attr;
  pthread_attr_init(&line_attr);
  pthread_create(&line_tid, &line_attr, verify_lines, NULL);

  pthread_t column_tid;
  pthread_attr_t column_attr;
  pthread_attr_init(&column_attr);
  pthread_create(&column_tid, &column_attr, verify_column, NULL);

  pthread_t sector_tid;
  pthread_attr_t sector_attr;
  pthread_attr_init(&sector_attr);
  pthread_create(&sector_tid, &sector_attr, verify_sector, NULL);

  pthread_join(line_tid,NULL);
  pthread_join(column_tid,NULL);
  pthread_join(sector_tid,NULL);

  if(errors){
    printf("The sudoku is not correct");
  }
  else{
    printf("The sudoku is correct");
  }

  return 0;
}
