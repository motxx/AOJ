#include <iostream>
using namespace std;

int main() {
  int n;
  int top, front, eside, temp, sum;
  string str;

  while (cin >> n, n) {
    // ﾃｨﾂｦﾂ凝｣ﾂ?暗｣ﾂつ凝･ﾂ?ｴﾃ｣ﾂ?ｮﾃｧﾂ環ｶﾃｦﾂ?凝｣ﾂつ津､ﾂｿﾂ敕ｦﾂ個?｣ﾂ?凖｣ﾂつ凝｣ﾂ?禿｣ﾂ?ｨﾃ｣ﾂ?ｧﾃ｣ﾂつｵﾃ｣ﾂつ､ﾃ｣ﾂつｳﾃ｣ﾂδｭﾃ｣ﾂ?ｮﾃ｣ﾂ?凖｣ﾂ?ｹﾃ｣ﾂ?ｦﾃ｣ﾂ?ｮﾃｩﾂ敖｢ﾃ｣ﾂ?ｮﾃｧﾂ環ｶﾃｦﾂ?凝｣ﾂ?古､ﾂｿﾂ敕ｦﾂ個?｣ﾂ?陛｣ﾂつ古｣ﾂつ?
    top = 1, front = 2, eside = 3;
    sum = top;
    for (int i = 0; i < n; i++) {
      cin >> str;
      if (str[0] == 'N') temp = top, top = front, front = 7 - temp;
      if (str[0] == 'E') temp = eside, eside = top, top = 7 - temp;
      if (str[0] == 'W') temp = top, top = eside, eside = 7 - temp;
      if (str[0] == 'S') temp = front, front = top, top = 7 - temp;
      if (str[0] == 'R') temp = front, front = eside, eside = 7 - temp;
      if (str[0] == 'L') temp = eside, eside = front, front = 7 - temp;
      sum += top;
    }
    cout << sum << endl;
  }

  return 0;
}