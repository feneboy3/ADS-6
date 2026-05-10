// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {

 private:
  struct Node {
    T value;
    Node* next;

    explicit Node(const T& val) {
      value = val;
      next = nullptr;
    }
  };

  Node* head;

 public:
  TPQueue() {
    head = nullptr;
  }

  ~TPQueue() {
    while (head != nullptr) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void push(const T& item) {
    Node* elem = new Node(item);

    if (head == nullptr || item.prior > head->value.prior) {
      elem->next = head;
      head = elem;
      return;
    }

    Node* cur = head;

    while (cur->next != nullptr &&
           cur->next->value.prior >= item.prior) {
      cur = cur->next;
    }

    elem->next = cur->next;
    cur->next = elem;
  }

  T pop() {
    if (head == nullptr) {
      throw "Queue is empty";
    }

    Node* tmp = head;
    T val = head->value;

    head = head->next;
    delete tmp;

    return val;
  }

  bool isEmpty() const {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
