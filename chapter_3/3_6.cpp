// В приюте для животных есть только собаки и кошки, а работа осуществляется в
// порядке очереди. Люди должны каждый раз забирать «самое старое» (по времени
// пребывания в питомнике) животное, но могут выбрать кошку или со­баку
// (животное в любом случае будет «самым старым»). Нельзя выбрать любое
// понравившееся животное. Создайте структуру данных, которая обеспечивает
// функционирование этой системы и реализует операции enqueue, dequeueAny,
// dequeueDog и dequeueCat. Разрешается использование встроенной структуры
// данных linkedlist

#include <cassert>
#include <iostream>
#include <list>
#include <string>

struct animal {
  std::string name;
};

struct dog : animal {
  dog(const std::string n) { name = n; }
};
struct cat : animal {
  cat(const std::string n) { name = n; }
};

class shelter {
 public:
  void enqueue(dog* d) { dogs_.push_back({counter_++, d}); }

  void enqueue(cat* c) { cats_.push_back({counter_++, c}); }

  animal* deque_any() {
    if (cats_.empty()) {
      return deque_dog();
    } else if (dogs_.empty()) {
      return deque_cat();
    } else {
      animal* a{};
      if (cats_.front().first < dogs_.front().first) {
        a = cats_.front().second;
        cats_.pop_front();
      } else {
        a = dogs_.front().second;
        dogs_.pop_front();
      }
      return a;
    }
  }

  animal* deque_dog() {
    if (dogs_.empty()) {
      return nullptr;
    } else {
      auto* d = dogs_.front().second;
      dogs_.pop_front();
      return d;
    }
  }

  animal* deque_cat() {
    if (cats_.empty()) {
      return nullptr;
    } else {
      auto* d = cats_.front().second;
      cats_.pop_front();
      return d;
    }
  }

 private:
  std::list<std::pair<int, animal*>> cats_;
  std::list<std::pair<int, animal*>> dogs_;
  int counter_{};
};

int main(int argc, char const* argv[]) {
  shelter sh;
  sh.enqueue(new cat{"tom"});
  sh.enqueue(new cat{"tor"});
  sh.enqueue(new dog{"feedo"});
  sh.enqueue(new cat{"tim"});
  sh.enqueue(new dog{"fargo"});

  assert(sh.deque_cat()->name == "tom");
  assert(sh.deque_dog()->name == "feedo");
  assert(sh.deque_any()->name == "tor");
  assert(sh.deque_dog()->name == "fargo");
  assert(sh.deque_cat()->name == "tim");

  std::cout << "done" << std::endl;

  return 0;
}
