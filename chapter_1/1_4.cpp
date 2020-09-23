// Напишите функцию, которая проверяет, является ли заданная строка
// перестановкой палиндрома. (Палиндром - слово или фраза, одинаково читающиеся
// в прямом и обратном направлении; перестановка - строка, содержащая те
// же символы в другом порядке.) Палиндром не ограничивается словами из
// словаря.
// Пpuмep:
// Ввод: TactСоа
// Вывод: True (перестановки: "tacocat", "atcocta", и т. д.)

#include <cassert>
#include <iostream>
#include <map>
#include <string>

bool is_permutation_polindrom(const std::string& str) {
  std::map<char, size_t> letters;
  for (auto c : str) {
    if (letters.find(c) == letters.end()) {
      letters.insert({c, 1});
    } else {
      letters[c]++;
    }
  }

  bool has_odd{};
  for (const auto& i : letters) {
    if (i.second % 2 == 1) {
      if (has_odd) {
        return false;
      }
      has_odd = true;
    }
  }

  return true;
}

int main(int argc, char const* argv[]) {
  assert(is_permutation_polindrom("tacocat") == true);
  assert(is_permutation_polindrom("tcaocta") == true);
  return 0;
}
