// Имеется изображение, представленное матрицей NxN; каждый пиксел пред­ставлен
// 4 байтами. Напишите метод для поворота изображения на 90 градусов. У дастся
// ли вам выполнить эту операцию «На месте»?

// a b c d   p l e a
// e f g h   q m f b
// l m n o   r n g c
// p q r s   s o h d

#include <cassert>
#include <iostream>

void rotate(char matrix[4][4], int size) {
  for (int layer = 0; layer < size / 2; layer++) {
    int first = layer;
    int last = size - 1 - layer;
    for (int i = first; i < last; i++) {
      int offset = i - first;

      int top = matrix[first][i];

      // left -> top
      matrix[first][i] = matrix[last - offset][first];

      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];

      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];

      // top to right
      matrix[i][last] = top;
    }
  }
}

int main(int argc, char const* argv[]) {
  char matrix[4][4]{{'a', 'b', 'c', 'd'},
                    {'e', 'f', 'g', 'h'},
                    {'l', 'm', 'n', 'o'},
                    {'p', 'q', 'r', 's'}};

  rotate(matrix, 4);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
