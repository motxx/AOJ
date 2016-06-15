#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

inline int prev(int idx, int size) {
  idx--;
  if (idx < 0) idx = size - 1;
  return idx;
}
inline void adv(int& idx, int size) {
  idx++;
  if (idx == size) idx = 0;
}

inline bool isNumber(const string& s, int& ret) {
  ret = -1;
  int tmp = 0;
  int const size = s.size();
  for (int i = 0; i < size; i++) {
    if (!isdigit(s[i])) return false;
    (tmp *= 10) += s[i] - '0';
  }
  ret = tmp;
  return true;
}

void rem(vector<int>& player, int& idx) {
  adv(idx, player.size());
  player.erase(player.begin() + prev(idx, player.size()));
  if (player.size() == 1)
    idx = 0;
  else if (idx != 0)
    idx--;
}

int main() {
  int M, N;
  while (cin >> M >> N && (M | N)) {
    int idx = 0;
    vector<int> player(M);
    for (int i = 0; i < M; i++) player[i] = i + 1;
    for (int fcnt = 1; fcnt <= N; fcnt++) {
      string s;
      cin >> s;
      if (player.size() == 1) continue;
      int num;
      if (s == "Fizz" && fcnt % 3 != 0)
        rem(player, idx);
      else if (s == "Buzz" && fcnt % 5 != 0)
        rem(player, idx);
      else if (s == "FizzBuzz" && fcnt % 15 != 0)
        rem(player, idx);
      else if (isNumber(s, num)) {
        if (num != fcnt)
          rem(player, idx);
        else if (num % 3 == 0)
          rem(player, idx);
        else if (num % 5 == 0)
          rem(player, idx);
        else if (num % 15 == 0)
          rem(player, idx);
        else
          adv(idx, player.size());
      } else {
        if (s == "Fizz" || s == "Buzz" || s == "FizzBuzz")
          adv(idx, player.size());
        else
          rem(player, idx);
      }
    }
    for (int i = 0; i < player.size(); i++) {
      if (i) cout << " ";
      cout << player[i];
    }
    cout << endl;
  }

  return 0;
}