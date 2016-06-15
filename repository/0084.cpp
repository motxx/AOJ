#include <iostream>
#include <vector>
using namespace std;

int main() {
  string str;
  vector<string> v;

  getline(cin, str);
  int cnt = 0;
  for (int i = 0; i <= str.size(); i++) {
    if ((str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '\0') &&
        (3 <= cnt && cnt <= 6))
      v.push_back(str.substr(i - cnt, cnt)), cnt = 0;
    else if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '\0')
      cnt = 0;
    else
      cnt++;
  }

  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1)
      cout << v.back() << endl;
    else
      cout << v[i] << " ";
  }

  return 0;
}