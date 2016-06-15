#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define BESTBMI 22
#define MAX 10000

class CDATA {
 public:
  int stnum;
  double hei, wei;
  double bmi;

  void setBMI() { bmi = wei / (hei * hei); }

  bool operator<(const CDATA &t) const {
    if (abs(22 - bmi) == abs(22 - t.bmi))
      return stnum < t.stnum;
    else
      return abs(22 - bmi) < abs(22 - t.bmi);
  }
};

int main() {
  int n;
  double h;
  CDATA person[MAX];

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> person[i].stnum >> h >> person[i].wei;
      person[i].hei = h / 100;
      person[i].setBMI();
    }

    stable_sort(person, person + n);

    cout << person[0].stnum << endl;
  }

  return 0;
}