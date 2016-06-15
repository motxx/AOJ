// 2013 TT 021 Div 2
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int w, h;
  string prgrm;
  int num;
  int px, py;
  int angle;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  for (;;) {
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    w--;
    h--;
    px = 0;
    py = 0;
    angle = 0;

    for (;;) {
      cin >> prgrm;
      if (prgrm == "RIGHT") {
        angle++;
        if (angle == 4) angle = 0;
        continue;

      } else if (prgrm == "LEFT") {
        angle--;
        if (angle == -1) angle = 3;
        continue;

      } else if (prgrm == "STOP") {
        cout << px + 1 << " " << py + 1 << endl;
        break;
      }

      cin >> num;

      if (prgrm == "FORWARD") {
        px += dx[angle] * num;
        py += dy[angle] * num;
        if (px < 0) px = 0;
        if (py < 0) py = 0;
        if (px > w) px = w;
        if (py > h) py = h;

      } else if (prgrm == "BACKWARD") {
        px -= dx[angle] * num;
        py -= dy[angle] * num;
        if (px < 0) px = 0;
        if (py < 0) py = 0;
        if (px > w) px = w;
        if (py > h) py = h;
      }
    }
  }

  return 0;
}