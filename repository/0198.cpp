#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

enum { TOP = 0, FRONT = 1, LEFT = 2, RIGHT = 3, BACK = 4, BOTTOM = 5 };
enum { WEST = 0, NORTH = 1, EAST = 2, SOUTH = 3 };

class Dice {
 private:
  int num[6];

 public:
  int getTop() { return num[TOP]; }
  int getBottom() { return num[BOTTOM]; }
  int getFront() { return num[FRONT]; }
  int getBack() { return num[BACK]; }
  int getLeft() { return num[LEFT]; }
  int getRight() { return num[RIGHT]; }

  void roll(int dir) {
    int tmp;
    switch (dir) {
      case EAST:
        tmp = num[RIGHT];
        num[RIGHT] = num[TOP];
        num[TOP] = num[LEFT];
        num[LEFT] = num[BOTTOM];
        num[BOTTOM] = tmp;
        break;

      case WEST:
        tmp = num[LEFT];
        num[LEFT] = num[TOP];
        num[TOP] = num[RIGHT];
        num[RIGHT] = num[BOTTOM];
        num[BOTTOM] = tmp;
        break;

      case NORTH:
        tmp = num[BOTTOM];
        num[BOTTOM] = num[FRONT];
        num[FRONT] = num[TOP];
        num[TOP] = num[BACK];
        num[BACK] = tmp;
        break;

      case SOUTH:
        tmp = num[BOTTOM];
        num[BOTTOM] = num[BACK];
        num[BACK] = num[TOP];
        num[TOP] = num[FRONT];
        num[FRONT] = tmp;
        break;
    }
  }

  void rightHandedRoll() {
    int tmp = num[FRONT];
    num[FRONT] = num[RIGHT];
    num[RIGHT] = num[BACK];
    num[BACK] = num[LEFT];
    num[LEFT] = tmp;
  }

  Dice() {}

  Dice(int t, int f, int l, int r, int b, int m) {
    num[TOP] = t, num[FRONT] = f, num[LEFT] = l, num[RIGHT] = r, num[BACK] = b,
    num[BOTTOM] = m;
  }
  Dice(vector<int> v) {
    num[TOP] = v[0], num[FRONT] = v[1], num[LEFT] = v[2], num[RIGHT] = v[3],
    num[BACK] = v[4], num[BOTTOM] = v[5];
  }

  bool equals(Dice rhs) const {
    for (int i = 0; i < 4; i++) {
      rhs.roll(NORTH);
      if (num[TOP] == rhs.getTop()) break;
      rhs.roll(WEST);
      if (num[TOP] == rhs.getTop()) break;
    }
    for (int i = 0; i < 4; i++) {
      if (check(rhs))
        return true;
      else
        rhs.rightHandedRoll();
    }
    return false;
  }

 private:
  bool check(const Dice& rhs) const {
    for (int i = 0; i < 6; i++) {
      if (num[i] != rhs.num[i]) return false;
    }
    return true;
  }
};

map<string, int> mp;

int main() {
  mp["Red"] = 0, mp["Yellow"] = 1, mp["Blue"] = 2, mp["Magenta"] = 3,
  mp["Green"] = 4, mp["Cyan"] = 5;
  int N;
  while (cin >> N && N) {
    vector<Dice> d;
    for (int i = 0; i < N; i++) {
      vector<int> v(6);
      for (int j = 0; j < 6; j++) {
        string s;
        cin >> s;
        v[j] = mp[s];
      }
      swap(v[2], v[3]);
      d.push_back(Dice(v));
    }

    int cnt = 0;
    bool update = true;
    while (update) {
      update = false;
      for (int i = 0; i < d.size(); i++) {
        for (int j = i + 1; j < d.size(); j++) {
          if (d[i].equals(d[j])) {
            d.erase(d.begin() + j);
            update = true;
            cnt++;
            goto NEXT;
          }
        }
      }
    NEXT:;
    }
    cout << cnt << endl;
  }

  return 0;
}