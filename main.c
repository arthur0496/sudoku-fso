#include <stdio.h>
int sudoku[9][9];

int main(){
  int line,column;

  FILE *sudoku_file;
  sudoku_file = fopen("sudoku.txt","r");
  
  for(line = 0; line < 9; line++){
    for(column = 0; column <9; column++){
      fscanf(sudoku_file,"%d",&sudoku[line][column]);
    }
  }

  fclose(sudoku_file);

  for(line = 0; line < 9; line++){
    for(column = 0; column <9; column++){
      printf("%d ",sudoku[line][column]);
    }
    printf("\n");
  }

  return 0;
}
