#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    int lunch_cnt = 0, dinner_cnt = 0, midnight_cnt = 0;
    int lok = 0, dok = 0, mok = 0;
    for (int i = 0; i < N; i++) {
      int h, m, mm;
      char colon;
      cin >> h >> colon >> m >> mm;
      if (h < 2) {
        h += 24;
      }
      if (m > mm) {
        mm += 60;
      }

      if (11 <= h && h < 15) {
        lunch_cnt++;
        if (mm - m <= 8) {
          lok++;
        }
      } else if (18 <= h && h < 21) {
        dinner_cnt++;
        if (mm - m <= 8) {
          dok++;
        }
      } else if (21 <= h && h < 26) {
        midnight_cnt++;
        if (mm - m <= 8) {
          mok++;
        }
      }
    }

    cout << "lunch ";
    if (lunch_cnt) {
      cout << 100 * lok / lunch_cnt << endl;
    } else
      cout << "no guest\n";
    cout << "dinner ";
    if (dinner_cnt) {
      cout << 100 * dok / dinner_cnt << endl;
    } else
      cout << "no guest\n";
    cout << "midnight ";
    if (midnight_cnt) {
      cout << 100 * mok / midnight_cnt << endl;
    } else
      cout << "no guest\n";
  }

  return 0;
}