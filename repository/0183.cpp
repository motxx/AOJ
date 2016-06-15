#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  char grid[3][3];
  while (1) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == '0') return 0;
      }
    }

    for (int i = 0; i < 3; i++) {
      bool b = 1, w = 1;
      for (int j = 0; j < 3; j++) {
        if (grid[i][j] == 'b')
          w = 0;
        else if (grid[i][j] == 'w')
          b = 0;
        else
          b = 0, w = 0;
      }
      if (b) {
        cout << 'b' << endl;
        goto EXIT;
      }
      if (w) {
        cout << 'w' << endl;
        goto EXIT;
      }
    }

    for (int i = 0; i < 3; i++) {
      bool b = 1, w = 1;
      for (int j = 0; j < 3; j++) {
        if (grid[j][i] == 'b')
          w = 0;
        else if (grid[j][i] == 'w')
          b = 0;
        else
          b = 0, w = 0;
      }
      if (b) {
        cout << 'b' << endl;
        goto EXIT;
      }
      if (w) {
        cout << 'w' << endl;
        goto EXIT;
      }
    }

    bool b, w;

    b = 1, w = 1;
    for (int i = 0; i < 3; i++) {
      if (grid[i][i] == 'b')
        w = 0;
      else if (grid[i][i] == 'w')
        b = 0;
      else
        b = 0, w = 0;
    }
    if (b) {
      cout << 'b' << endl;
      goto EXIT;
    }
    if (w) {
      cout << 'w' << endl;
      goto EXIT;
    }

    b = 1, w = 1;
    for (int i = 0; i < 3; i++) {
      if (grid[i][2 - i] == 'b')
        w = 0;
      else if (grid[i][2 - i] == 'w')
        b = 0;
      else
        b = 0, w = 0;
    }
    if (b) {
      cout << 'b' << endl;
      goto EXIT;
    }
    if (w) {
      cout << 'w' << endl;
      goto EXIT;
    }

    cout << "NA" << endl;

  EXIT:;
  }

  return 0;
}