// Напишите метод, заменяющий все пробелы в строке символами '%20'. Можете
// считать, что длина строки позволяет сохранить дополнительные символы,
// а фактическая длина строки известна заранее. (Примечание: при реализации
// метода нajava для выполнения операции "на месте" используйте символьный
// массив.)
// Ilpuмep:
// Ввод: "Mr John Smith    ", 13
// Вывод: "Mr%20John%20Smith"

#include <cassert>
#include <iostream>
#include <queue>
#include <string>

std::string& replace_spaces(std::string& str) {
  std::queue<char> queue;

  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      queue.push('%');
      queue.push('2');
      queue.push('0');
    }
    if (!queue.empty()) {
      if (str[i] != ' ') {
        queue.push(str[i]);
      }
      str[i] = queue.front();
      queue.pop();
    }
  }

  return str;
}

int main(int argc, char const* argv[]) {
  std::string str{"Mr John Smith    "};
  assert(replace_spaces(str) == "Mr%20John%20Smith");
  return 0;
}
