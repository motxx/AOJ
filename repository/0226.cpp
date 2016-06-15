#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string strH, strB;
  int hNum, bNum;

  while (1) {
    cin >> strH >> strB;
    if (strH == "0" && strB == "0") break;

    hNum = bNum = 0;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (strH[i] == strB[j]) {
          if (i == j)
            hNum++;
          else
            bNum++;
        }
      }
    }

    cout << hNum << " " << bNum << endl;
  }

  return 0;
}