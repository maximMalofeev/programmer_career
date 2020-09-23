// Существуют три вида модифицирующих операций со строками: вставка
// символа, удаление символа и замена символа. Напишите функцию, которая
// проверяет, находятся ли две строки на расстоянии одной модификации (или
// нуля модификаций).
// Ilpuмep:
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

bool is_one_modification_distance(const std::string& str_1,
                                  const std::string& str_2) {
  auto s1_l = str_1.length();
  auto s2_l = str_2.length();
  if (std::abs(static_cast<int64_t>(s1_l - s2_l)) > 1) {
    return false;
  }
  size_t i1{}, i2{};

  int mod_count{};
  while (i1 < s1_l && i2 < s2_l) {
    if (str_1[i1] != str_2[i2]) {
      mod_count++;
      if (s1_l == s2_l) {
        i1++;
        i2++;
      } else if (s1_l < s2_l) {
        i2++;
      } else {
        i1++;
      }
    } else {
      i1++;
      i2++;
    }
  }

  return mod_count < 2;
}

int main(int argc, char const* argv[]) {
  assert(is_one_modification_distance("pale", "ple") == true);
  assert(is_one_modification_distance("pales", "pale") == true);
  assert(is_one_modification_distance("pale", "bale") == true);
  assert(is_one_modification_distance("pale", "bake") == false);
  assert(is_one_modification_distance("pale", "pl") == false);
  return 0;
}
