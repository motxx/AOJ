#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class Stack {
 private:
  struct Node {
    Node *next;
    T data;

    Node(Node *next_ = NULL, T data_ = 0) : next(next_), data(data_) {}
  };

  int size_;
  Node *top;

 public:
  Stack() : size_(0) {}
  ~Stack() {
    while (!isEmpty()) pop();
  }

  void push(T data) {
    Node *node = new Node(top, data);
    top = node;
    size_++;
  }

  T pop() {
    if (isEmpty()) throw std::runtime_error("nothing in stack");

    T data;
    Node *d = top;

    data = d->data;
    top = d->next;
    delete d;
    size_--;

    return data;
  }

  bool isEmpty() { return size_ == 0; }
};

int main() {
  Stack<int> st;
  std::string str;

  while (std::cin >> str) {
    if (isdigit(str[0])) {
      st.push(atoi(str.c_str()));
    } else {
      int x = st.pop();
      int y = st.pop();
      if (str == "+") {
        st.push(y + x);
      } else if (str == "-") {
        st.push(y - x);
      } else if (str == "*") {
        st.push(y * x);
      } else
        throw std::runtime_error("undefined operator '" + str + "'");
    }
  }
  std::cout << st.pop() << '\n';

  return 0;
}