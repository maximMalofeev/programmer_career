#pragma once
#include <iostream>
#include <set>
#include <stack>
#include <unordered_set>

template <typename T>
struct node {
  node(const T& data) { data_ = data; }

  void append(T data) {
    node* end = new node{data};
    node* n = this;
    while (n->next_) {
      n = n->next_;
    }
    n->next_ = end;
  }

  void print() {
    node* n = this;
    while (n) {
      std::cout << n->data_ << " ";
      n = n->next_;
    }
    std::cout << std::endl;
  }

  void remove_duplicates() {
    std::set<T> exists;
    node* prev = this;
    node* cur = prev->next_;
    while (cur) {
      if (exists.find(cur->data_) != exists.end()) {
        node* to_remove = cur;
        prev->next_ = cur->next_;
        cur = cur->next_;
        delete to_remove;
      } else {
        exists.insert(cur->data_);
        prev = cur;
        cur = cur->next_;
      }
    }
  }

  T nth_from_the_end(int num) {
    node* target = this;
    node* n = this->next_;
    num--;
    while (n) {
      if (num) {
        num--;
      } else {
        target = target->next_;
      }
      n = n->next_;
    }

    return target->data_;
  }

  bool is_palindrome() {
    node<T>* n = this;
    node<T>* reversed{};
    while (n) {
      node<T>* h = new node<T>{n->data_};
      h->next_ = reversed;
      reversed = h;
      n = n->next_;
    }

    n = this;
    while (n) {
      if (n->data_ != reversed->data_) {
        return false;
      }

      n = n->next_;
      reversed = reversed->next_;
    }

    return true;
  }

  bool is_palindrome_2() {
    node<T>* slow = this;
    node<T>* fast = this;

    std::stack<T> stack;
    while (fast && fast->next_) {
      stack.push(slow->data_);
      slow = slow->next_;
      fast = fast->next_->next_;
    }

    if (fast) {
      slow = slow->next_;
    }

    while (!stack.empty()) {
      T val = stack.top();
      if (val != slow->data_) {
        return false;
      }

      stack.pop();
      slow = slow->next_;
    }

    return true;
  }

  node<T>* get_loop_start() {
    node<T>* n = this;
    std::unordered_set<node<T>*> hash;
    while (n) {
      if (hash.find(n) != hash.end()) {
        return n;
      }
      hash.insert(n);
      n = n->next_;
    }

    return nullptr;
  }

  node<T>* get_loop_start_2() {
    node<T>* slow = this;
    node<T>* fast = this;

    while (fast && fast->next_) {
      fast = fast->next_->next_;
      slow = slow->next_;

      if (fast == slow) {
        break;
      }
    }

    if (!fast || !fast->next_) {
      return nullptr;
    }

    slow = this;
    while (slow != fast) {
      slow = slow->next_;
      fast = fast->next_;
    }

    return slow;
  }

  T data_;
  node* next_{};
};
