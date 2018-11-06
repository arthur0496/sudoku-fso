#include <pthread.h>

int sudoku[9][9];
int errors = 0;

int verify(int *array){
  int number[9] = {0},count;
  
  for(count = 0; count < 9; count++){
    int value = array[count];
    if(number[value-1]){
      return 0;  
    }
    number[value-1]++;
  }

  return 1;
}

void* verify_lines(void *arg){
  int line;
  for(line = 0; line < 9; line ++){
    if(!verify(sudoku[line])){
      errors++;
    }
  }

  pthread_exit(0);
}

void* verify_column(void *arg){
  int columns[9][9],line,column;
  for(line = 0; line < 9; line ++){
    for(column = 0; column < 9; column++){
      columns[column][line] = sudoku[line][column];
    }
  }

  for(column = 0; column < 9; column ++){
    if(!verify(columns[column])){
      errors++;
    }
  }
  pthread_exit(0);
}

void* verify_sector(void *arg){
  int sectors[9][9],i,j,n = 0;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      sectors[0][n] = sudoku[i][j];
      sectors[1][n] = sudoku[i][j+3];
      sectors[2][n] = sudoku[i][j+6];
      sectors[3][n] = sudoku[i+3][j];
      sectors[4][n] = sudoku[i+3][j+3];
      sectors[5][n] = sudoku[i+3][j+6];
      sectors[6][n] = sudoku[i+6][j];
      sectors[7][n] = sudoku[i+6][j+3];
      sectors[8][n] = sudoku[i+6][j+6];
      n++;
    }
  }

  for(n = 0; n < 9; n++){
    if(!verify(sectors[n])){
      errors++;
    } 
  }

  pthread_exit(0);
}
