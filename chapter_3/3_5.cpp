// Напишите программу сортировки стека, в результате которой наименьший эле­мент
// оказывается на вершине стека. Вы можете использовать дополнительный временный
// стек, но элементы не должны копироваться в другие структуры данных (например,
// в массив). Стек должен поддерживать следующие опера­ции: push, рор, peek,
// isEmpty.

#include <iostream>
#include <stack>

template <typename T>
void sort_stack(std::stack<T>& stack) {
  if(stack.empty()) {
    return;
  }
  std::stack<T> tmp;
  tmp.push(stack.top());
  stack.pop();

  while(!stack.empty()){
    T top = stack.top();
    stack.pop();

    if(top > tmp.top()){
      tmp.push(top);
    } else {
      while(!tmp.empty() && tmp.top() > top) {
        stack.push(tmp.top());
        tmp.pop();
      }
      tmp.push(top);
    }
  }

  while(!tmp.empty()) {
    stack.push(tmp.top());
    tmp.pop();
  }
}

int main(int argc, char const* argv[]) {
  std::stack<int> stack;
  stack.push(2);
  stack.push(5);
  stack.push(3);
  stack.push(7);
  stack.push(4);
  stack.push(1);

  sort_stack(stack);

  while (!stack.empty()) {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << std::endl;

  return 0;
}
