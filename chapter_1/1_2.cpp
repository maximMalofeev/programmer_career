// Для двух строк напишите метод, определяющий, является ли одна строка
// перестановкой другой.

#include <cassert>
#include <iostream>
#include <string>

bool is_permutations(const std::string& s_1, const std::string& s_2) {
  if (s_1.length() != s_2.length()) {
    return false;
  }

  char letters[256]{0};

  for (auto c : s_1) {
    letters[c]++;
  }

  for (auto c : s_2) {
    if (--letters[c] < 0) {
      return false;
    }
  }

  return true;
}

int main(int argc, char const* argv[]) {
  assert(is_permutations("abcd", "dcba") == true);
  assert(is_permutations("abcd", "dcb") == false);
  assert(is_permutations("", "") == true);
  return 0;
}
