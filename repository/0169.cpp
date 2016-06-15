#include <bits/stdc++.h>

using namespace std;

int main() {
  while (1) {
    int card = 0;
    int save = 0;
    for (;;) {
      int add;
      scanf("%d", &add);
      if (!add) return 0;
      if (add == 1) {
        save++;
      } else if (10 <= add && add <= 13)
        card += 10;
      else
        card += add;

      char ch;
      scanf("%c", &ch);
      if (ch == '\n') break;
    }

    card += save;

    if (card > 21) {
      card = 0;
    } else {
      for (int i = 0; i < save; i++) {
        if (card + 10 <= 21)
          card += 10;
        else
          break;
      }
    }

    if (card > 21) card = 0;
    cout << card << endl;
  }

  return 0;
}