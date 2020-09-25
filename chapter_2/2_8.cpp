// Для кольцевого связного списка реализуйте алгоритм, возвращающий на­чальный
// узел петли. Определеиие Кольцевой связный список -это связный список, в
// котором указатель следу­ющего узла ссылается на более ранний узел, образуя
// петлю. Пример: Ввод: A->B- >C->D->E->C (предьщущий узел С) Вывод: с

#include <cassert>

#include "node.h"

int main(int argc, char const* argv[]) {
  node<int> node1{1};
  node<int> node2{2};
  node<int> node3{3};
  node<int> node4{4};
  node<int> node5{5};
  node<int> node6{6};

  node1.next_ = &node2;
  node2.next_ = &node3;
  node3.next_ = &node4;
  node4.next_ = &node5;
  node5.next_ = &node6;
  node6.next_ = &node3; 

  auto* loop_start = node1.get_loop_start();
  assert(loop_start != nullptr);
  assert(loop_start->data_ == 3);
  loop_start = node1.get_loop_start_2();
  assert(loop_start != nullptr);
  assert(loop_start->data_ == 3);

  std::cout << "done" << std::endl;

  return 0;
}
