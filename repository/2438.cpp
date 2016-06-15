#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string in[50000];
int linum, N;

struct object {
  vector<string> key;
  vector<string> property;
  vector<object *> child;
};

object *parse(int pindent = -1) {
  object *res = new object;

  while (linum < N) {
    int indent = 0;
    for (; in[linum][indent] == ' ';) indent++;
    if (indent <= pindent) break;

    int colon = in[linum].find(":");
    string key = in[linum].substr(indent, colon - indent);
    if (colon == in[linum].size() - 1) {
      res->key.push_back(key);
      res->property.push_back("__object");

      linum++;
      res->child.push_back(parse(indent));
    } else {
      res->key.push_back(key);
      res->property.push_back(in[linum].substr(colon + 2));
      res->child.push_back(NULL);

      linum++;
    }
  }
  return res;
}

const string NG = "no such property";

string find(const object *root, const vector<string> v) {
  for (int i = 0; i < v.size() - 1; i++) {
    bool ok = 0;
    for (int j = 0; j < root->key.size(); j++) {
      if (root->key[j] == v[i]) {
        if (root->property[j] != "__object") break;
        root = root->child[j];
        ok = 1;
        break;
      }
    }
    if (!ok) return NG;
  }

  for (int i = 0; i < root->key.size(); i++) {
    if (root->key[i] == v.back()) {
      if (root->property[i] == "__object")
        return "object";
      else
        return "string \"" + root->property[i] + "\"";
    }
  }
  return NG;
}

int main() {
  vector<string> Query;
  string query;
  getline(cin, query);
  for (int i = 0; i < query.size(); i++)
    if (query[i] == '.') query[i] = ' ';
  stringstream ss(query);
  while (ss >> query) Query.push_back(query);

  linum = 0;
  N = 0;
  while (getline(cin, in[N])) N++;
  object *yaml = parse();

  cout << find(yaml, Query) << endl;

  return 0;
}