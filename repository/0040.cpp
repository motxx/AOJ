#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define DCRPT_MAX 26

int Alpha;
int Beta;  // 0 -> 25
int fCnt;

int F(int g) { return (Alpha * g + Beta) % 26; }

char f(char c) { return F(c - 'a') + 'a'; }

string decode(string str, int cnt) {
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < cnt; j++) {
      str[i] = f(str[i]);
    }
  }

  return str;
}

string Decrypt(string str, int cnt) {
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < cnt; j++) {
      if ('a' <= str[i] && str[i] <= 'z') {
        str[i] = f(str[i]);
      }
    }
  }

  return str;
}

bool affineCipher(vector<string> vec) {
  for (Alpha = 1; Alpha < 26; Alpha++) {
    if (Alpha % 2 == 0 || Alpha % 13 == 0) continue;
    for (Beta = 0; Beta < 26; Beta++) {
      for (int i = 1; i < DCRPT_MAX; i++) {
        for (int j = 0; j < vec.size(); j++) {
          string dec = decode(vec[j], i);
          if (dec == "this" || dec == "that") {
            fCnt = i;
            return true;
          }
        }
      }
    }
  }

  return false;
}

int main() {
  string cryptogram;
  int tcase;

  cin >> tcase;
  cin.ignore();

  for (int i = 0; i < tcase; i++) {
    getline(cin, cryptogram);

    vector<string> v;
    stringstream ss(cryptogram);

    while (true) {
      string str;
      ss >> str;
      if (str == "") break;
      if (str.size() == 4) {
        v.push_back(str);
      }
    }

    if (affineCipher(v)) {
      cout << Decrypt(cryptogram, fCnt) << endl;
    }
  }

  return 0;
}