#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  typedef pair<int, int> Pii;

  int N;

  while (cin >> N && N) {
    vector<Pii> SCORE(N);

    for (int m = 0; m < N; m++) {
      cin >> SCORE[m].second;

      int all = 0;
      int strike[11] = {};

      for (int i = 1; i <= 10; i++) {
        int sc;
        cin >> sc;

        if (strike[i - 1] == 2) all += sc;
        if (i - 2 >= 0 && strike[i - 1] == 2 && strike[i - 2] == 2) all += sc;
        if (strike[i - 1] == 1) all += sc;

        if (sc == 10) {
          all += sc;
          strike[i] = 2;
        } else {
          int add;
          cin >> add;
          if (strike[i - 1] == 2) all += add;
          all += sc + add;
          if (sc + add == 10) strike[i] = 1;
        }
      }

      if (strike[10] == 2) {
        int sc, add;
        cin >> sc >> add;
        all += sc + add;
        if (strike[9] == 2) all += sc;
      } else if (strike[10] == 1) {
        int sc;
        cin >> sc;
        all += sc;
      }

      SCORE[m].first = -all;
    }

    sort(SCORE.begin(), SCORE.end());

    for (int i = 0; i < N; i++) {
      cout << SCORE[i].second << ' ' << -SCORE[i].first << endl;
    }
  }

  return 0;
}