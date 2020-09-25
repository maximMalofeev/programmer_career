// Реализуйте функцию, проверяющую, является ли связный список палиндромом.

#include "node.h"
#include <cassert>

int main(int argc, char const *argv[])
{
  node<int> n{1};
  n.append(2);
  n.append(3);
  n.append(2);
  n.append(1);
  assert(n.is_palindrome() == true);
  assert(n.is_palindrome_2() == true);

  node<int> n_1{1};
  n_1.append(2);
  n_1.append(3);
  n_1.append(2);
  n_1.append(2);
  assert(n_1.is_palindrome() == false);
  assert(n_1.is_palindrome_2() == false);

  return 0;
}
