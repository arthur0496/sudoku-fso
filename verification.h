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
