#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string str;
  double a, b;

  while (getline(cin, str)) {
    stack<double> st;
    stringstream ss(str);
    string s;

    while (ss >> s) {
      if (s.size() > 1 || isdigit(s[0])) {
        a = atof(s.c_str());
        st.push(a);
      } else if (s == "+") {
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        st.push(b + a);
      } else if (s == "-") {
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        st.push(b - a);
      } else if (s == "*") {
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        st.push(b * a);
      } else if (s == "/") {
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        st.push(b / a);
      }
    }
    printf("%.6lf\n", st.top());
  }

  return 0;
}