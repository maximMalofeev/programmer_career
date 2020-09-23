// Реализуйте алгоритм, определяющий, все ли символы в строке встречаются
// только один раз. А если при этом запрещено использование дополнительных
// структур данных?

#include <iostream>
#include <string>
#include <cassert>
#include <memory>
#include <bitset>

bool is_no_duplicates(const std::string& str) {
  if (str.length() <= 1) {
    return true;
  }

  std::bitset<256> bitset;

  for(size_t i = 0; i < str.length(); i++){
    auto current = str[i];
    if(bitset[current]){
      return false;
    }
    bitset[current] = true;
  }

  return true;
}

int main(int argc, char const* argv[]) {
  assert(is_no_duplicates("abcd") == true);
  assert(is_no_duplicates("abcb") == false);
  assert(is_no_duplicates("") == true);
  assert(is_no_duplicates("a") == true);
  assert(is_no_duplicates("abcda") == false);
  return 0;
}
