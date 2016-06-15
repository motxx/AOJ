#include <iostream>

using namespace std;

int main() {
  int N;

  while (cin >> N && N) {
    int hist[10] = {};
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      hist[a]++;
    }
    for (int i = 0; i < 10; i++) {
      if (hist[i]) {
        for (int j = 0; j < hist[i]; j++) {
          cout << '*';
        }
        cout << endl;
      } else {
        cout << "-" << endl;
      }
    }
  }

  return 0;
}