#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

#define MP make_pair
#define F first
#define S second

enum { INQ, SIT, LEAVE };
int now;
bool fiveempty, twoempty;
int ans[100], seats[17];
map<int, deque<pair<int, int> > > mp;
inline int num(int i) { return i % 5 == 1 ? 5 : 2; }
inline int eattime(int i) { return 17 * (i % 2) + 3 * (i % 3) + 19; }

void update_emptyseats() {
  bool fe = 0, te = 0;
  rep(i, 13) if (seats[i] == -1 && seats[i + 1] == -1 && seats[i + 2] == -1 &&
                 seats[i + 3] == -1 && seats[i + 4] == -1) {
    fe = 1;
  }
  rep(i, 16) if (seats[i] == -1 && seats[i + 1] == -1) { te = 1; }
  fiveempty = fe, twoempty = te;
}

void sit(int id) {
  ans[id] = now - 5 * id;
  mp[now + eattime(id)].push_front(MP(id, (int)LEAVE));

  if (num(id) == 5)
    rep(i, 13) if (seats[i] == -1 && seats[i + 1] == -1 && seats[i + 2] == -1 &&
                   seats[i + 3] == -1 && seats[i + 4] == -1) {
      rep(j, 5) seats[i + j] = id;
      update_emptyseats();
      return;
    }

  if (num(id) == 2) rep(i, 16) if (seats[i] == -1 && seats[i + 1] == -1) {
      rep(j, 2) seats[i + j] = id;
      update_emptyseats();
      return;
    }
}

void leave(int id) {
  rep(i, 17) {
    if (seats[i] == id) {
      rep(j, num(id)) { seats[i + j] = -1; }
      update_emptyseats();
      return;
    }
  }
}

int main() {
  rep(i, 100) mp[5 * i].push_back(MP(i, (int)INQ));
  queue<int> waitingQ;
  fiveempty = twoempty = 1;
  memset(seats, -1, sizeof seats);
  while (!mp.empty()) {
    now = mp.begin()->F;
    deque<pair<int, int> >& Q = mp.begin()->S;
    int id = Q.front().F;
    int act = Q.front().S;
    Q.pop_front();
    if (act == SIT) {
      sit(id);
      if (!waitingQ.empty() && ((num(waitingQ.front()) == 5 && fiveempty) ||
                                (num(waitingQ.front()) == 2 && twoempty))) {
        Q.push_front(MP(waitingQ.front(), (int)SIT));
        waitingQ.pop();
      }
    } else if (act == INQ) {
      if (!waitingQ.empty()) {
        waitingQ.push(id);
      } else if (num(id) == 5 && fiveempty) {
        sit(id);
      } else if (num(id) == 2 && twoempty) {
        sit(id);
      } else {
        waitingQ.push(id);
      }
    } else if (act == LEAVE) {
      leave(id);
      if (!waitingQ.empty() && ((num(waitingQ.front()) == 5 && fiveempty) ||
                                (num(waitingQ.front()) == 2 && twoempty))) {
        Q.push_front(MP(waitingQ.front(), (int)SIT));
        waitingQ.pop();
      }
    }
    if (Q.empty()) mp.erase(mp.begin());
  }
  for (int N; cin >> N;) cout << ans[N] << endl;

  return 0;
}