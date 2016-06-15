#include <iostream>
using namespace std;

int main(void) {
  int n;
  string event;

  cin >> n;
  while (n--) {
    int out = 3;
    int ret = 0;
    int runner = 0;

    while (out) {
      cin >> event;
      if (event == "HIT") runner++;
      if (event == "OUT") out--;
      if (event == "HOMERUN") {
        ret += (runner + 1);
        runner = 0;
      }
      if (runner == 4) {
        runner--;
        ret++;
      }
    }
    cout << ret << endl;
  }

  return 0;
}