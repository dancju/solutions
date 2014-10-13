#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define endl '\n'

const long double PI = acos(-1.L);
using namespace std;
template<class T> T maximize(T &a, const T &b) { return a = max(a, b); }
template<class T> T minimize(T &a, const T &b) { return a = min(a, b); }

char s[10000][76];
short fail[10001] = {-1};

inline char row(int r, int c) { return s[r][c]; }
inline char col(int r, int c) { return s[c][r]; }

inline int bazinga(int r, int c, char s(int, int)) {
  bitset<10001> res;
  for(int _r = 0; _r<r; _r++) {
    for(int i = 0, j = -1; i<c; )
      if(j==-1 || s(_r, i)==s(_r, j))
        fail[++i] = ++j;
      else
        j = fail[j];
    bitset<10001> _res;
    for(int i = c; i; i = fail[i])
      _res[c-fail[i]] = 1;
    if(_r)
      res &= _res;
    else
      res = _res;
    if(res.count()==1)
      return c;
  }
  for(int i = 1; i<=c; i++)
    if(res[i])
      return i;
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  int r, c;
  scanf("%d%d", &r, &c);
  for(int i = 0; i<r; i++)
    scanf("%s", s[i]);
  printf("%d\n", bazinga(r, c, row)*bazinga(c, r, col));
  return 0;
}
