#include <assert.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 1000000000;

struct Data {
  int id;
  int st;
  int num;
  Data(int id, int st, int num) : id(id), st(st), num(num) {}
  bool operator<(const Data& rhs) const { return st < rhs.st; }
};

int N;
vector<Data> storage;

void dump() {
  cout << "-----------------------------" << endl;
  for (int i = 0; i < (int)storage.size(); i++) {
    cout << "storage[" << i << "]:" << endl;
    cout << "id: " << storage[i].id << " st: " << storage[i].st
         << " num: " << storage[i].num << endl;
  }
  cout << "-----------------------------" << endl;
}

void write(const int id, int remain) {
  int st = 0;
  while (remain > 0) {
    int num = -1;
    int into = -1;

    for (int i = 0; i < (int)storage.size(); i++) {
      if (st < storage[i].st) {
        num = min(remain, storage[i].st - st);
        into = i;
        break;
      } else if (st < storage[i].st + storage[i].num) {
        st = st + storage[i].num;
      }

      if (st > LIMIT) return;
    }

    if (num == -1) {
      // insert data back
      num = remain;
      into = storage.size();
    }
    storage.insert(storage.begin() + into, Data(id, st, num));
    remain -= num;
    assert(remain >= 0);
  }
}

class EqualsID {
 private:
  int id;

 public:
  EqualsID(int id) : id(id) {}
  bool operator()(const Data& d) { return d.id == id; }
};
void del(int id) {
  storage.erase(remove_if(storage.begin(), storage.end(), EqualsID(id)),
                storage.end());
}

int refer(int sect) {
  for (int i = 0; i < (int)storage.size(); i++) {
    if (storage[i].st <= sect && sect < storage[i].st + storage[i].num) {
      return storage[i].id;
    }
  }
  return -1;
}

int main() {
  while (scanf("%d", &N) && N) {
    storage.clear();
    for (int i = 0; i < N; i++) {
      char ch;
      cin >> ch;  // scanf("%c", &ch);
      if (ch == 'W') {
        int id, num;
        scanf("%d%d", &id, &num);
        write(id, num);
        // dump();
      }
      if (ch == 'D') {
        int id;
        scanf("%d", &id);
        del(id);
      }
      if (ch == 'R') {
        int sect;
        scanf("%d", &sect);
        printf("%d\n", refer(sect));
      }
    }
    puts("");
  }
  return 0;
}