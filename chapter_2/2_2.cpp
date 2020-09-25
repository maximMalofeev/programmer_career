// Реализуйте алгоритм для нахождения в односвязном списке k-го элемента с конца

#include <cassert>

#include "node.h"

int main(int argc, char const *argv[]) {
  node<int> n{1};
  n.append(2);
  n.append(3);
  n.append(4);
  n.append(5);
  n.append(6);
  n.append(7);
  n.append(8);

  assert(n.nth_from_the_end(3) == 6);
  assert(n.nth_from_the_end(1) == 8);
  assert(n.nth_from_the_end(8) == 1);

  return 0;
}
