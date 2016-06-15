#include <bits/stdc++.h>

using namespace std;

string colors[8] = {"black", "blue",    "lime",   "aqua",
                    "red",   "fuchsia", "yellow", "white"};

int c(char ch) {
  if (isdigit(ch)) return ch - '0';
  return ch - 'a' + 10;
}

int d(string s) { return c(s[0]) * 16 + c(s[1]); }

int main() {
  int colR[8];
  int colG[8];
  int colB[8];

  colR[0] = d("00");
  colG[0] = d("00");
  colB[0] = d("00");
  colR[1] = d("00");
  colG[1] = d("00");
  colB[1] = d("ff");
  colR[2] = d("00");
  colG[2] = d("ff");
  colB[2] = d("00");
  colR[3] = d("00");
  colG[3] = d("ff");
  colB[3] = d("ff");
  colR[4] = d("ff");
  colG[4] = d("00");
  colB[4] = d("00");
  colR[5] = d("ff");
  colG[5] = d("00");
  colB[5] = d("ff");
  colR[6] = d("ff");
  colG[6] = d("ff");
  colB[6] = d("00");
  colR[7] = d("ff");
  colG[7] = d("ff");
  colB[7] = d("ff");

  /*
  for(int i=0; i<8; i++) {
    colR[i] = i & 1 ? 255 : 0;
    colG[i] = i & 2 ? 255 : 0;
    colB[i] = i & 4 ? 255 : 0;
  }
  */

  string s;

  while (cin >> s) {
    if (s == "0") break;

    s = s.substr(1);

    int R = d(s.substr(0, 2));
    int G = d(s.substr(2, 2));
    int B = d(s.substr(4, 2));

    int minD = (int)1e9;
    int id = -1;
    for (int i = 0; i < 8; i++) {
      if (minD > pow(R - colR[i], 2.0) + pow(G - colG[i], 2.0) +
                     pow(B - colB[i], 2.0)) {
        id = i;
        minD = pow(R - colR[i], 2.0) + pow(G - colG[i], 2.0) +
               pow(B - colB[i], 2.0);
      }
    }

    cout << colors[id] << endl;
  }

  return 0;
}