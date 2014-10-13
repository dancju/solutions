#include<algorithm>
#include<iostream>
#include<limits>
#include<vector>
using namespace std;

inline int nextInt() {
  int t;
  cin >> t;
  return t;
}

inline short nextShort() {
  short t;
  cin >> t;
  return t;
}

int main() {
  ios::sync_with_stdio(false);
  short nCase = nextShort();
  while (nCase--) {
    int w = nextInt(), h = nextInt(), n = nextInt();
    vector< pair<double, bool> > c;
    c.reserve(n+n);
    while (n--) {
      int x = nextInt(), y = nextInt();
      short a = nextShort(), b = nextShort();
      if (a==0 && (x<=0 || x>=w))
        continue;
      if (b==0 && (y<=0 || y>=h))
        continue;
      double lo = 0, hi = numeric_limits<double>::max();
      if (a > 0) {
        lo = max(lo, -(double)x/a);
        hi = min(hi, (double)(w-x)/a);
      }
      else if (a < 0) {
        lo = max(lo, (double)(w-x)/a);
        hi = min(hi, -(double)x/a);
      }
      if (b > 0) {
        lo = max(lo, -(double)y/b);
        hi = min(hi, (double)(h-y)/b);
      }
      else if (b < 0) {
        lo = max(lo, (double)(h-y)/b);
        hi = min(hi, -(double)y/b);
      }
      if (lo < hi) {
        c.push_back(pair<double, bool>(hi, false));
        c.push_back(pair<double, bool>(lo, true));
      }
    }
    sort(c.begin(), c.end());
    int t = 0, resu = 0;
    for (vector<pair<double, bool> >::iterator i = c.begin(); i != c.end(); i++)
      if (i->second) {
        t++;
        resu = max(resu, t);
      }
      else
        t--;
    cout << resu << endl;
  }
  return 0;
}
