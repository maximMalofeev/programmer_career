// Проверьте, пересекаются ли два заданных (одно-)связных списка. Верните узел
// пересечения. Учтите, что пересечение определяется ссылкой, а не зна­чением.
// Иначе говоря, если k-й узел первого связного списка точно совпадает (по
// ссылке) с j-м узлом второго связного списка, то списки считаются
// пере­секающимися.

#include "node.h"
#include <algorithm>
#include <cassert>

template<typename T>
node<T>* get_intersection(node<T>* h1, node<T>* h2) {
  if(!h1 || !h2) {
    return nullptr;
  }

  node<T>* n1 = h1;
  int n1_len{1};
  node<T>* n2 = h2;
  int n2_len{1};

  while(n1->next_ || n2->next_) {
    if(n1->next_) {
      n1_len++;
      n1 = n1->next_;
    }
    if(n2->next_) {
      n2_len++;
      n2 = n2->next_;
    }
  }

  if(n1 != n2) {
    return nullptr;
  }

  node<T>* longer = n1_len > n2_len ? h1 : h2;
  node<T>* shorter = n1_len > n2_len ? h2 : h1;

  for(int i = 0; i < std::abs(n1_len - n2_len); i++) {
    longer = longer->next_;
  }

  for(int i = 0; i < std::min(n1_len, n2_len); i++) {
    if(longer == shorter){
      return longer;
    }
    longer = longer->next_;
    shorter = shorter->next_;
  }

  return nullptr;
}

int main(int argc, char const *argv[]) {
  node<int> n1{1};
  node<int> n2{2};
  node<int> n3{3};
  node<int> n4{4};
  node<int> n33{33};
  node<int> n44{44};
  node<int> n5{5};
  node<int> n6{6};
  node<int> n7{7};

  n1.next_ = &n2;
  n2.next_ = &n3;
  n3.next_ = &n4;
  n4.next_ = &n5;
  n5.next_ = &n6;
  n6.next_ = &n7;

  n33.next_ = &n44;
  n44.next_ = &n5;

  n1.print();
  n33.print();

  auto* intr = get_intersection(&n1, &n33);
  assert(intr->data_ == 5);

  std::cout << "intersection is " << intr->data_ << std::endl;

  return 0;
}
