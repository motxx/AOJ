#include <iostream>
#include <stack>
using namespace std;

int main() {
  string str;

  while (getline(cin, str)) {
    if (str == ".") break;

    string s;
    for (unsigned i = 0; i < str.size(); i++)
      if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
        s.push_back(str[i]);

    stack<char> st;
    bool ok = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') st.push(s[i]);
      if (s[i] == '[') st.push(s[i]);

      if (s[i] == ')') {
        if (st.empty()) {
          ok = 0;
          break;
        }
        if (st.top() != '(') {
          ok = 0;
          break;
        }
        st.pop();
      }

      if (s[i] == ']') {
        if (st.empty()) {
          ok = 0;
          break;
        }
        if (st.top() != '[') {
          ok = 0;
          break;
        }
        st.pop();
      }
    }
    cout << (ok && st.empty() ? "yes" : "no") << endl;
  }

  return 0;
}