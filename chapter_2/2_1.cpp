// Напишите код для удаления дубликатов из несортированного связного списка.

#include <iostream>
#include <set>
#include "node.h"

int main(int argc, char const* argv[]) {
  node<int> n(1);
  n.append(2);
  n.append(3);
  n.append(4);
  n.append(3);
  n.append(5);

  n.print();

  n.remove_duplicates();

  n.print();

  return 0;
}
