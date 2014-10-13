#include<algorithm>
#include<deque>
#include<iostream>
#define FOR(i,b,e) for(__typeof(b)i=(b);i!=(e);i++)

using namespace std;

struct Package {
  int x, y, weight, dist2Origin, dist, dp;
} pkg[100001];
deque<int> q;

inline int func(int i) { return pkg[i].dp+pkg[i+1].dist2Origin-pkg[i+1].dist; }

int main() {
  ios::sync_with_stdio(false);
  short nCase;
  cin >> nCase;
  pkg[0].x = pkg[0].y = pkg[0].weight = pkg[0].dist = pkg[0].dist2Origin = 0;
  while(nCase--) {
    short capacity;
    int n;
    cin >> capacity >> n;
    FOR(i, 1, n+1) {
      cin >> pkg[i].x >> pkg[i].y >> pkg[i].weight;
      pkg[i].weight += pkg[i-1].weight;
      pkg[i].dist2Origin = abs(pkg[i].x)+abs(pkg[i].y);
      pkg[i].dist = pkg[i-1].dist
        +abs(pkg[i].x-pkg[i-1].x)
        +abs(pkg[i].y-pkg[i-1].y);
    }
    q.clear();
    FOR(i, 1, n+1) {
      while(!q.empty() && func(q.back())>=func(i-1))
        q.pop_back();
      q.push_back(i-1);
      while(!q.empty() && pkg[i].weight-pkg[q.front()].weight>capacity)
        q.pop_front();
      pkg[i].dp = pkg[i].dist2Origin+pkg[i].dist+func(q.front());
    }
    cout << pkg[n].dp << "\n";
    if(nCase > 0)
      cout << "\n";
  }
  return 0;
}
