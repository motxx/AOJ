#include <iostream>
using namespace std;

int main() {
  int n, q, era[1000], west[1000];
  string name[1000];

  while (cin >> n >> q && (n | q)) {
    for (int i = 0; i < n; i++) {
      cin >> name[i] >> era[i] >> west[i];
    }

    for (int i = 0; i < q; i++) {
      int year;
      int f = 0;
      cin >> year;
      for (int j = 0; j < n; j++) {
        if (west[j] - era[j] < year && year <= west[j]) {
          cout << name[j] << " " << year - west[j] + era[j] << endl;
          f = 1;
          break;
        }
      }
      if (!f) cout << "Unknown" << endl;
    }
  }

  return 0;
}