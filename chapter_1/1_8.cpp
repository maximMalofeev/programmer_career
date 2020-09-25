// Напишите алгоритм, реализующий следующее условие: если элемент матрицы MxN
// равен О, то весь столбец и вся строка обнуляются.

#include <iostream>

template<int N, int M>
void null_row_and_column(char matrix[N][M]) {
  bool rows[M] {false};
  bool columns[N] {false};
  for(int i = 0; i < N; i++) {
    for(int j = 0 ; j < M; j++) {
      if(matrix[i][j] == '0'){
        rows[j] = true;
        columns[i] = true;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0 ; j < M; j++) {
      if(rows[j] || columns[i]){
        matrix[i][j] = '0';
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  char matrix[5][4]{
    {'1','1','1','1'},
    {'0','1','1','1'},
    {'1','1','1','1'},
    {'1','1','0','1'},
    {'1','1','1','1'}
  };

  null_row_and_column<5,4>(matrix);

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
