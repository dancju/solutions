#include<algorithm>
#include<array>
#include<bitset>
#include<complex>
#include<deque>
#include<forward_list>
#include<functional>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>

const long double PI = 2*acos(.0L);
typedef long long LLONG;
typedef unsigned long long ULLONG;
using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};

struct SortByX {
  bool operator()(Point a, Point b) {
    if(fabs(a.x-b.x)>1e-8)
      return a.x<b.x;
    return a.y<b.y;
  }
} sortByX;

double t;
vector<Point> res;

void dfs(Point a, Point b) {
  if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) <= 4*t*t)
    return;
  Point
    c((3*a.x + b.x)/4, (3*a.y + b.y)/4),
    d((a.x + 3*b.x)/4, (a.y + 3*b.y)/4),
    e((a.x+b.x)/2+(a.y-b.y)*sqrt(3.l)/4, (a.y+b.y)/2-(a.x-b.x)*sqrt(3.l)/4);
  res.push_back(c);
  res.push_back(d);
  res.push_back(e);
  dfs(c, e);
  dfs(e, d);
}

int main() {
  short iCase = 0;
  Point a, b;
  while(scanf("%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &t), t>=1) {
    res.clear();
    res.push_back(a);
    res.push_back(b);
    dfs(a, b);
    sort(res.begin(), res.end(), sortByX);
    printf("Case %hd:\n%lu\n", ++iCase, res.size());
    for(auto i = res.begin(); i != res.end(); i++)
      printf("%.5lf %.5lf\n", i->x, i->y);
  }
  return 0;
}
