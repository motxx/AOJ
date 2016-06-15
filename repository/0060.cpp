#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  int deck[10];
  while (cin >> a >> b >> c) {
    for (int i = 0; i < 10; i++) deck[i] = i + 1;
    deck[a - 1] = 1000;
    deck[b - 1] = 1000;
    deck[c - 1] = 1000;
    sort(deck, deck + 10);
    for (int i = 0; i < 4; i++) {
      if (a + b + deck[i] > 20) {
        goto aho;
      }
    }
    cout << "YES" << endl;
    continue;
  aho:
    cout << "NO" << endl;
  }

  return 0;
}