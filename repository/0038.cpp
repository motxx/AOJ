#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int card[5];

  while (scanf("%d,%d,%d,%d,%d\n", &card[0], &card[1], &card[2], &card[3],
               &card[4]) != EOF) {
    int isStraight = 1;
    sort(card, card + 5);
    if (card[0] == card[1] - 1 || card[4] == 13 && card[0] == 1) isStraight++;
    for (int i = 1; i < 4; i++) {
      if (card[i] + 1 == card[i + 1]) isStraight++;
    }

    if (isStraight == 5) {
      cout << "straight" << endl;
      continue;
    }

    int cdcnt[14];
    fill(cdcnt, cdcnt + 14, 0);
    for (int i = 0; i < 5; i++) {
      cdcnt[card[i] - 1]++;
    }

    int mxpair = 0;
    for (int i = 0; i < 13; i++) {
      mxpair = max(mxpair, cdcnt[i]);
    }

    if (mxpair == 4) {
      cout << "four card" << endl;
    }

    else if (mxpair == 3) {
      for (int i = 0; i < 5; i++) {
        if (cdcnt[card[i] - 1] == 2) {
          cout << "full house" << endl;
          goto Fin;
        }
      }
      cout << "three card" << endl;
    }

    else if (mxpair == 2) {
      int twopaircnt = 0;

      for (int i = 0; i < 5; i++) {
        if (cdcnt[card[i] - 1] == 2) twopaircnt++;
      }
      if (twopaircnt == 2) {
        cout << "one pair" << endl;
      } else {
        cout << "two pair" << endl;
      }
    }

    else {
      cout << "null" << endl;
    }

  Fin:;
  }

  return 0;
}