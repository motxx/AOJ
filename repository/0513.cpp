#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define EACH(i, c) \
  for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

void cut(vector<int>& cards, int k) {
  int const N = cards.size();
  vector<int> ncards;

  for (int i = k; i < N; i++) ncards.push_back(cards[i]);
  for (int i = 0; i < k; i++) ncards.push_back(cards[i]);

  cards = ncards;
}

void shuffle(vector<int>& cards) {
  int const N = cards.size();
  vector<int> ncards;

  int fst = 0, snd = N / 2;
  for (int i = 0; i < N; i++) {
    if (i % 2)
      ncards.push_back(cards[snd++]);
    else
      ncards.push_back(cards[fst++]);
  }

  cards = ncards;
}

int main() {
  int n;

  cin >> n;
  vector<int> cards(2 * n);
  for (int i = 0; i < 2 * n; i++) cards[i] = i + 1;
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    if (k)
      cut(cards, k);
    else
      shuffle(cards);
  }

  EACH(i, cards)
  cout << *i << endl;

  return 0;
}