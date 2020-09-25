// Допустим, что существует метод isSubstring, проверяющий, является ли одно
// слово подстрокой другого. Для двух строк sl и s2 напишите код, кото­рый
// проверяет, получена ли строка s2 циклическим сдвигом sl, используя только
// один вызов метода isSubstring (пример: слово waterbottle получено циклическим
// сдвигом erbottlewat).

#include <cassert>
#include <iostream>
#include <string>

bool is_substring(const std::string& s1, const std::string& s2) {
  if (s2.length() > s1.length()) {
    return false;
  }
  if (s2.length() == 0) {
    return true;
  }

  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == s2[0]) {
      bool isSub{true};
      for (int j = 1; j < s2.length(); j++) {
        if (s1[(i + j) % s1.length()] != s2[j]) {
          isSub = false;
          break;
        }
      }
      if (isSub) {
        return true;
      }
    }
  }

  return false;
}

int main(int argc, char const* argv[]) {
  assert(is_substring("erbottlewat", "waterbottle") == true);
  assert(is_substring("erbottlewat", "water") == true);
  assert(is_substring("erbottlewat", "waterpool") == false);
  return 0;
}
