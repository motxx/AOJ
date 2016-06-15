#include <bits/stdc++.h>

using namespace std;

enum { TOP = 0, BOTTOM, FRONT, BACK, LEFT, RIGHT };
enum { WEST = 0, NORTH, EAST, SOUTH };

class Dice {
 private:
  int num[6];

 public:
  int getTop() { return num[TOP]; }
  int getBottom() { return num[BOTTOM]; }
  int getFront() { return num[FRONT]; }
  int getBack() { return num[BACK]; }
  int getLeft() { return num[LEFT]; }
  int getRight() { return num[RIGHT]; }

  void roll(int dir) {
    int tmp;
    switch (dir) {
      case EAST:
        tmp = num[RIGHT];
        num[RIGHT] = num[TOP];
        num[TOP] = num[LEFT];
        num[LEFT] = num[BOTTOM];
        num[BOTTOM] = tmp;
        break;

      case WEST:
        tmp = num[LEFT];
        num[LEFT] = num[TOP];
        num[TOP] = num[RIGHT];
        num[RIGHT] = num[BOTTOM];
        num[BOTTOM] = tmp;
        break;

      case NORTH:
        tmp = num[BOTTOM];
        num[BOTTOM] = num[FRONT];
        num[FRONT] = num[TOP];
        num[TOP] = num[BACK];
        num[BACK] = tmp;
        break;

      case SOUTH:
        tmp = num[BOTTOM];
        num[BOTTOM] = num[BACK];
        num[BACK] = num[TOP];
        num[TOP] = num[FRONT];
        num[FRONT] = tmp;
        break;
    }
  }

 public:
  Dice(int t, int f) {
    num[TOP] = t;
    num[BOTTOM] = 7 - t;
    num[FRONT] = f;
    num[BACK] = 7 - f;

    switch (num[TOP]) {
      case 1:
        switch (num[FRONT]) {
          case 3:
            num[LEFT] = 2;
            break;
          case 5:
            num[LEFT] = 3;
            break;
          case 4:
            num[LEFT] = 5;
            break;
          case 2:
            num[LEFT] = 4;
            break;
        }
        break;
      case 2:
        switch (num[FRONT]) {
          case 1:
            num[LEFT] = 3;
            break;
          case 3:
            num[LEFT] = 6;
            break;
          case 4:
            num[LEFT] = 1;
            break;
          case 6:
            num[LEFT] = 4;
            break;
        }
        break;
      case 3:
        switch (num[FRONT]) {
          case 1:
            num[LEFT] = 5;
            break;
          case 2:
            num[LEFT] = 1;
            break;
          case 6:
            num[LEFT] = 2;
            break;
          case 5:
            num[LEFT] = 6;
            break;
        }
        break;
      case 4:
        switch (num[FRONT]) {
          case 1:
            num[LEFT] = 2;
            break;
          case 2:
            num[LEFT] = 6;
            break;
          case 5:
            num[LEFT] = 1;
            break;
          case 6:
            num[LEFT] = 5;
            break;
        }
        break;
      case 5:
        switch (num[FRONT]) {
          case 1:
            num[LEFT] = 4;
            break;
          case 3:
            num[LEFT] = 1;
            break;
          case 4:
            num[LEFT] = 6;
            break;
          case 6:
            num[LEFT] = 3;
            break;
        }
        break;
      case 6:
        switch (num[FRONT]) {
          case 2:
            num[LEFT] = 3;
            break;
          case 3:
            num[LEFT] = 5;
            break;
          case 4:
            num[LEFT] = 2;
            break;
          case 5:
            num[LEFT] = 4;
            break;
        }
        break;
    }
    num[RIGHT] = 7 - num[LEFT];
  }
};

char field[150][310][310];
class BiasedDices {
 private:
  typedef pair<int, pair<int, int> > Position;  // z, y, x
#define Z first
#define Y second.first
#define X second.second

  vector<pair<Dice, Position> > bdices;

  enum { SY = 150, SX = 150 };

 private:
  bool canDrop(const Position* pos) {
    if (pos->Z == 0) return false;
    return field[pos->Z - 1][pos->Y][pos->X] == -1;
  }

  void drop(Position* pos) {
    field[pos->Z - 1][pos->Y][pos->X] = field[pos->Z][pos->Y][pos->X];
    field[pos->Z][pos->Y][pos->X] = -1;
    pos->Z--;
  }

  bool canRollAndFall(Position* pos, int dir) {
    switch (dir) {
      case NORTH:
        return (int)field[pos->Z - 1][pos->Y + 1][pos->X] == -1;

      case SOUTH:
        return (int)field[pos->Z - 1][pos->Y - 1][pos->X] == -1;

      case EAST:
        return (int)field[pos->Z - 1][pos->Y][pos->X + 1] == -1;

      case WEST:
        return (int)field[pos->Z - 1][pos->Y][pos->X - 1] == -1;
    }

    return false;
  }

 public:
  BiasedDices() { memset(field, -1, sizeof field); }

  void setDice(int t, int f) {
    int droppingPoint = 0;
    while (field[droppingPoint][SY][SX] != -1) droppingPoint++;
    field[droppingPoint][SY][SX] = bdices.size();
    Position pos;
    pos.X = SX, pos.Y = SY, pos.Z = droppingPoint;
    bdices.push_back(make_pair(Dice(t, f), pos));
  }

  void rollAndFall(Dice* dice, Position* pos, int rolldir) {
    dice->roll(rolldir);
    switch (rolldir) {
      case NORTH:
        field[pos->Z - 1][pos->Y + 1][pos->X] = field[pos->Z][pos->Y][pos->X];
        field[pos->Z][pos->Y][pos->X] = -1;
        pos->Y++;
        pos->Z--;
        break;

      case SOUTH:
        field[pos->Z - 1][pos->Y - 1][pos->X] = field[pos->Z][pos->Y][pos->X];
        field[pos->Z][pos->Y][pos->X] = -1;
        pos->Y--;
        pos->Z--;
        break;

      case EAST:
        field[pos->Z - 1][pos->Y][pos->X + 1] = field[pos->Z][pos->Y][pos->X];
        field[pos->Z][pos->Y][pos->X] = -1;
        pos->X++;
        pos->Z--;
        break;

      case WEST:
        field[pos->Z - 1][pos->Y][pos->X - 1] = field[pos->Z][pos->Y][pos->X];
        field[pos->Z][pos->Y][pos->X] = -1;
        pos->X--;
        pos->Z--;
        break;
    }
  }

  void simulate() {
    while (1) {
      bool update = false;

      for (int id = 0; id < (int)bdices.size(); id++) {
        Dice* dice = &bdices[id].first;
        Position* pos = &bdices[id].second;

        while (1) {
          while (canDrop(pos)) {
            drop(pos);
          }
          if (pos->Z == 0) {
            break;
          } else {
            // roll
            vector<pair<int, int> > rolldirs;  // rollfrontnum, rolldir
            if (dice->getFront() >= 4)
              rolldirs.push_back(make_pair(dice->getFront(), (int)NORTH));
            if (dice->getBack() >= 4)
              rolldirs.push_back(make_pair(dice->getBack(), (int)SOUTH));
            if (dice->getLeft() >= 4)
              rolldirs.push_back(make_pair(dice->getLeft(), (int)WEST));
            if (dice->getRight() >= 4)
              rolldirs.push_back(make_pair(dice->getRight(), (int)EAST));

            sort(rolldirs.begin(), rolldirs.end(), greater<pair<int, int> >());

            bool repeat = false;
            for (int ii = 0; ii < (int)rolldirs.size(); ii++) {
              if (rolldirs[ii].first < 4) {
                break;
              }
              if (canRollAndFall(pos, rolldirs[ii].second)) {
                rollAndFall(&bdices.back().first, pos, rolldirs[ii].second);
                update = true;
                repeat = true;
                break;
              }
            }
            if (repeat) continue;
            break;
          }
        }

      }  // for id

      if (!update) break;
    }
  }

  void printResult() {
    int res[6] = {};
    for (int i = 0; i < (int)bdices.size(); i++) {
      Dice* rawDice = &bdices[i].first;
      Position* pos = &bdices[i].second;

      if (field[pos->Z + 1][pos->Y][pos->X] == -1) {
        res[rawDice->getTop() - 1]++;
      }
    }

    for (int i = 0; i < 6; i++) {
      if (i) cout << ' ';
      cout << res[i];
    }
    cout << endl;
  }
};

int main() {
  int N;
  int T = 0;
  while (cin >> N && N) {
    T++;
    BiasedDices bd;
    for (int i = 0; i < N; i++) {
      int t, f;
      cin >> t >> f;
      bd.setDice(t, f);
      bd.simulate();
    }
    bd.printResult();
  }

  return 0;
}