#include <assert.h>
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

string parse_target;
string::const_iterator iter, last;

bool consume(char expected) {
  if (*iter == expected) {
    iter++;
    return true;
  } else {
    assert(false);
  }
}
bool consume_if(char expected) {
  if (*iter == expected) {
    consume(expected);
    return true;
  }
  return false;
}
void debugger() {
  for (auto tmp = iter; tmp != last; tmp++) cout << *tmp;
  cout << endl;
}

double number() {
  string str;
  for (; isdigit(*iter) || *iter == '-'; iter++) {
    str += *iter;
  }
  return stod(str);
}

typedef complex<double> Point;
typedef vector<Point> Line;
enum { undefined_style, line_style, point_style };
struct result_type {
  int style_;
  Line line_;
  Point point_;
  result_type(Point const& a, Point const& b) : style_(line_style), point_() {
    line_.push_back(a), line_.push_back(b);
  }
  result_type(Point p) : style_(point_style), line_(), point_(p) {}
  result_type(double x, double y)
      : style_(point_style), line_(), point_(x, y) {}
  result_type() : style_(undefined_style), line_(), point_() {}
};

double dot(Point const& a, Point const& b) { return real(conj(a) * b); }
double cross(Point const& a, Point const& b) { return imag(conj(a) * b); }

Point intersection(Line const& a, Line const& b) {
  Point va = a[1] - a[0], vb = b[1] - b[0];
  return a[0] + va * cross(vb, b[0] - a[0]) / cross(vb, va);
}

Point projection_point(Line const& l, Point const& p) {
  double k = dot(l[1] - l[0], p - l[0]) / norm(l[1] - l[0]);
  return l[0] + k * (l[1] - l[0]);
}

Point reflection_point(Line const& l, Point const& p) {
  return p + 2. * (projection_point(l, p) - p);
}

result_type make_symmetric_point(result_type line, result_type p) {
  if (line.style_ == point_style) swap(line, p);
  return result_type(reflection_point(line.line_, p.point_));
}

result_type rec();

result_type term() {
  result_type ret;
  if ((*iter == '(') && (isdigit(*(iter + 1)) || *(iter + 1) == '-')) {
    consume('(');
    auto lhs = number();
    consume(',');
    auto rhs = number();
    consume(')');
    return {lhs, rhs};
  } else if (consume_if('(')) {
    auto expr = rec();
    consume(')');
    return expr;
  } else {
    if (ret.style_ == undefined_style) ret = rec();
    consume(')');
    return ret;
  }
}

result_type rec() {
  result_type ret = term();

  for (; iter < last;) {
    if (consume_if('@')) {
      auto rhs = term();
      if (ret.style_ == point_style && rhs.style_ == point_style)
        ret = {ret.point_, rhs.point_};
      else if (ret.style_ == line_style && rhs.style_ == line_style)
        ret = intersection(ret.line_, rhs.line_);
      else
        ret = make_symmetric_point(ret, rhs);
    } else {
      break;
    }
  }
  return ret;
}

int main() {
  for (; getline(cin, parse_target);) {
    if (parse_target == "#") {
      break;
    }
    iter = parse_target.begin(), last = parse_target.end();
    auto res = rec();
    printf("%.8f %.8f\n", res.point_.real(), res.point_.imag());
  }

  return 0;
}