#include <iostream>

using namespace std;

#define MAX_DEPTH (50000)

long long leaf[MAX_DEPTH];

// ﾃｦﾂ慊ｨﾃ｣ﾂつ津･ﾂ?催･ﾂｸﾂｰﾃｧﾂ堋?｣ﾂ?ｫﾃｧﾂ板淌ｦﾂ按静｣ﾂ?凖｣ﾂつ凝｣ﾂつ､ﾃ｣ﾂδ｡ﾃ｣ﾂδｼﾃ｣ﾂつｸﾃ｣ﾂつ津｣ﾂ?療｣ﾂ?ｦﾃ｣ﾂ??｣ﾂ?敕｣ﾂ?ｮﾃ｣ﾂ?ｨﾃ｣ﾂ?催ｦﾂｳﾂｨﾃｧﾂ崢ｮﾃ｣ﾂ?凖｣ﾂつ凝ｨﾂ堕嘉｣ﾂ?ｮﾃｦﾂｷﾂｱﾃ｣ﾂ?陛｣ﾂつ津ｨﾂｨﾂ佚ｩﾂ個ｲ
// ﾃ･ﾂ青古｣ﾂ?佚ｦﾂｷﾂｱﾃ｣ﾂ?陛｣ﾂ?ｧﾃ｣ﾂ?づ｣ﾂつ古｣ﾂ?ｰﾃｧﾂｺﾂ湘｣ﾂつ?｣ﾂつ嘉｣ﾂつ古｣ﾂつ凝｣ﾂ?ｮﾃ｣ﾂ?ｧﾃ｣ﾂ??ｦﾂｷﾂｱﾃ｣ﾂ?陛ｦﾂｯﾂ偲｣ﾂ?ｫ
// nC2
// ﾃ｣ﾂつ津ｧﾂｮﾂ療･ﾂ?ｺﾃ｣ﾂ?療｣ﾂ?淌ｧﾂｷﾂ湘･ﾂ陳古｣ﾂつ津ｦﾂｱﾂづ｣ﾂつ?｣ﾂつ古｣ﾂ?ｰﾃ｣ﾂつ暗｣ﾂ??
int main() {
  string s;
  int size;

  cin >> s;
  size = s.size();

  int depth = -1;

  for (int i = 0; i < size; i++) {
    if (s[i] == '(')
      leaf[++depth]++;
    else {
      leaf[--depth]++;
    }
  }

  long long ans = 0;
  for (int i = 0; leaf[i] > 0; i++) {
    ans += (leaf[i] * (leaf[i] - 1)) / 2;
  }

  cout << ans << endl;

  return 0;
}