#include <iostream>
using namespace std;

int main() {
  int n;
  int a, b;
  int maxv = -1;
  int id = 21;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (maxv == b) {
      if (id > a) {
        maxv = b;
        id = a;
      }
    } else if (maxv < b) {
      maxv = b;
      id = a;
    }
  }

  cout << id << " " << maxv << endl;
  return 0;
}