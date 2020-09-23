// Реализуйте метод для выполнения простейшего сжатия строк с использова­нием
// счетчика повторяющихся символов. Например, строка ааЬсссссааа пре­вращается в
// а2b1с5аЗ. Если ~сжатая» строка не становится короче исходной, то метод
// возвращает исходную строку. Предполагается, что строка состоит только из букв
// верхнего и нижнего регистра (a-z).

#include <cassert>
#include <iostream>
#include <string>

std::string compress(const std::string& in) {
  if (in.length() <= 3) {
    return in;
  }

  std::string compressed;
  compressed.push_back(in[0]);
  char prev = in[0];
  int counter = 1;
  for (size_t i = 1; i < in.length(); i++) {
    if (in[i] == prev) {
      counter++;
    } else {
      compressed.append(std::to_string(counter));
      counter = 1;
      compressed.push_back(in[i]);
      prev = in[i];
    }
  }
  compressed.append(std::to_string(counter));

  if (compressed.length() >= in.length()) {
    return in;
  } else {
    return compressed;
  }
}

int main(int argc, char const* argv[]) {
  assert(compress("aabcccccaaa") == "a2b1c5a3");
  return 0;
}
