#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int const S = 32;
    int now = S;
    int counter = 0;

    while (1) {
      now -= (now - 1) % 5;
      cout << now << endl;
      if (now == 1) break;
      now -= arr[counter % N];
      counter++;
      cout << now << endl;
    }
    cout << 0 << endl;
  }

  return 0;
}