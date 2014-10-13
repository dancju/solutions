#include<iostream>
#include<limits>
#include<list>
#include<vector>

using namespace std;

inline int nextShort() {
  short t;
  cin >> t;
  return t;
}

short root, k, resu;
vector<list<short> > adj;
vector<bool> book;

short dp(short s) {
  if (s!=root && adj[s].size()==1)
    return 1;
  short up = numeric_limits<short>::min(), lo = numeric_limits<short>::max();
  book[s] = true;
  for (list<short>::iterator t = adj[s].begin(); t!=adj[s].end(); t++)
    if (!book[*t]) {
      short tmp = dp(*t);
      up = max(up, tmp);
      lo = min(lo, tmp);
    }
  book[s] = false;
  lo = -lo;
  if (up == lo)
    return 0;
  else if (up == k) {
    if (s!=root)
      resu++;
    return -k+1;
  }
  else if (up > lo)
    return up+1;
  else
    return -lo+1;
}

int main() {
  ios::sync_with_stdio(false);
  short nCase = nextShort();
  while (nCase--) {
    short n = nextShort();
    root = nextShort()-1;
    k = nextShort();
    adj.assign(n, list<short>());
    book.assign(n, false);
    while (--n) {
      short u = nextShort()-1, v = nextShort()-1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    resu = 0;
    dp(root);
    cout << resu << '\n';
  }
  return 0;
}
