// Два числа хранятся в виде связных списков, в которых каждый узел
// пред­ставляет один разряд. Все цифры хранятся в обратном порядке, при этом
// младший разряд (единицы) хранится в начале списка. Напишите функцию, которая
// суммирует два числа и возвращает результат в виде связного списка. Пример:
// Ввод: (7->1->6) + (5->9- >2), то есть 617 + 295. Вывод: 2 ->1->9, то есть 912

#include "node.h"

template <typename T>
node<T>* sum(node<T>* n1, node<T>* n2) {
  node<T>* s{};
  T reserv{};
  while (n1 || n2) {
    T sum{};
    sum += reserv;

    if (n1) {
      sum += n1->data_;
      n1 = n1->next_;
    }

    if (n2) {
      sum += n2->data_;
      n2 = n2->next_;
    }

    if (sum >= 10) {
      reserv = 1;
      sum -= 10;
    } else {
      reserv = 0;
    }

    if (s) {
      s->append(sum);
    } else {
      s = new node<T>{sum};
    }
  }

  if (s && reserv) {
    s->append(reserv);
  }

  return s;
}

int main(int argc, char const* argv[]) {
  node<int> n1{7};
  n1.append(1);
  n1.append(6);

  node<int> n2{5};
  n2.append(9);
  n2.append(2);

  auto* s = sum(&n1, &n2);
  s->print();

  return 0;
}
