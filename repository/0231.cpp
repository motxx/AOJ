#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n;

  while (cin >> n, n) {
    vector<pair<int, int> > v(n * 2);
    for (int i = 0; i < n; i++) {
      int mass, begin, end;
      cin >> mass >> begin >> end;
      // ﾃｦﾂｩﾂ凝｣ﾂ?ｸﾃ｣ﾂ?凝｣ﾂ?凝｣ﾂつ凝ｨﾂｲﾂ?ｨﾂ債ｷﾃ｣ﾂ?ｮﾃ･ﾂ｢ﾂ療ｦﾂｸﾂ崚｣ﾂ?ｮﾃ･ﾂ｢ﾂεｧﾂ閉古｣ﾂ?ｯﾃｦﾂｸﾂ｡ﾃ｣ﾂつ甘･ﾂｧﾂ凝｣ﾂつ?｣ﾂ?ｨﾃｧﾂｵﾂづ｣ﾂつ?
      v[i * 2] = make_pair(begin, mass);
      v[i * 2 + 1] = make_pair(end, -mass);
    }
    // ﾃ､ﾂｺﾂ凝｣ﾂ?ｮﾃｨﾂｵﾂｷﾃ｣ﾂつ甘｣ﾂつ津ｦﾂ卍づｧﾂｳﾂｻﾃ･ﾂ按療ｩﾂ??｣ﾂ?ｫﾃ｣ﾂつｽﾃ｣ﾂδｼﾃ｣ﾂδ?
    sort(v.begin(), v.end());

    int load = 0;
    bool isOk = true;
    for (int i = 0; i < 2 * n; i++) {
      load += v[i].second;
      if (load > 150) isOk = false;
    }
    cout << (isOk ? "OK" : "NG") << endl;
  }

  return 0;
}