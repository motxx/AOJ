#include <assert.h>
#include <iostream>
using namespace std;

struct Node;
typedef Node* Node_ptr;
struct Node {
  int key;
  Node_ptr prev, next;

  Node(int key_ = -1, Node_ptr prev_ = NULL, Node_ptr next_ = NULL)
      : key(key_), prev(prev_), next(next_) {}
};

class LinkedList {
 private:
  Node_ptr head, tail;

 public:
  LinkedList() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }

  ~LinkedList() {
    Node_ptr d = head->next;
    for (Node_ptr iter = head->next->next; iter != tail; iter = iter->next) {
      delete d;
      d = iter;
    }
    delete d;
    delete head;
    delete tail;
  }

  bool empty() { return head->next == tail; }

  void insert(int x) {
    Node_ptr nd = new Node(x, head, head->next);
    nd->next->prev = nd;
    head->next = nd;
  }

  void erase(int x) {
    Node_ptr tprev, tnext;
    bool deleted = false;
    for (Node_ptr iter = head->next; iter != tail; iter = iter->next) {
      if (iter->key == x) {
        tprev = iter->prev, tnext = iter->next;
        delete iter;
        deleted = true;
        break;
      }
    }
    if (!deleted) return;
    tprev->next = tnext;
    tnext->prev = tprev;
  }

  void erase_first() {
    if (empty()) return;
    Node_ptr tnext = head->next->next;
    delete head->next;
    head->next = tnext;
    tnext->prev = head;
  }

  void erase_last() {
    if (empty()) return;
    Node_ptr tprev = tail->prev->prev;
    delete tail->prev;
    tprev->next = tail;
    tail->prev = tprev;
  }

  void print() {
    for (Node_ptr iter = head->next; iter != tail; iter = iter->next) {
      if (iter != head->next) cout << " ";
      cout << iter->key;
    }
    cout << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int Q_num;
  cin >> Q_num;
  LinkedList list;
  for (int q = 0; q < Q_num; q++) {
    string s;
    cin >> s;
    if (s == "deleteFirst")
      list.erase_first();
    else if (s == "deleteLast")
      list.erase_last();
    else {
      int x;
      cin >> x;
      if (s == "insert") list.insert(x);
      if (s == "delete") list.erase(x);
    }
  }

  list.print();

  return 0;
}