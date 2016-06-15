#include <bits/stdc++.h>

using namespace std;

struct Data {
  string s;
  int t;
};

class Queue {
 private:
  int head, tail;
  enum { MAX = 100000 };
  Data deq[MAX + 1];

 public:
  Queue() : head(0), tail(0) {}

  void push(Data p) {
    deq[tail++] = p;
    if (tail == MAX + 1) tail = 0;
  }

  Data pop() {
    Data ret = deq[head++];
    if (head == MAX + 1) head = 0;
    return ret;
  }

  bool empty() { return head == tail; }
};

int main() {
  int N, Q;
  cin >> N >> Q;

  Queue que;

  for (int i = 0; i < N; i++) {
    string s;
    int t;
    cin >> s >> t;
    que.push((Data){s, t});
  }

  int elasped = 0;

  while (!que.empty()) {
    Data dat = que.pop();
    if (dat.t > Q) {
      dat.t -= Q;
      elasped += Q;
      que.push(dat);
    } else {
      elasped += dat.t;
      cout << dat.s << ' ' << elasped << endl;
    }
  }

  return 0;
}