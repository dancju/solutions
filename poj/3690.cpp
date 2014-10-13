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

using namespace std;
const long double PI = acos(-1.L);
template<class T> T maximize(T &a, const T &b) { return a = max(a, b); }
template<class T> T minimize(T &a, const T &b) { return a = min(a, b); }
typedef long long ll;
typedef unsigned long long ull;

int h0, w0, h1, w1, n;
ull d0[1000][1000], d1[50];
char _s[1001];

inline void bazinga0() {
  ull ONE = (1ULL<<w1)-1;
  for(int i = 0; i<h0; i++) {
    scanf("%s", _s);
    ull _ = 0;
    for(int j = 0; j<w1; j++)
      _ = (_<<1)|(_s[j]=='*');
    d0[0][i] = _;
    for(int j = w1; j<w0; j++)
      d0[j-w1+1][i] = (_ = ((_<<1)&ONE)|(_s[j]=='*'));
  }
}

char fail[50+100] = {-1};
inline bool bazinga1() {
  for(int i = 0; i<h1; i++) {
    scanf("%s", _s);
    d1[i] = 0;
    for(int j = 0; j<w1; j++)
      d1[i] = (d1[i]<<1)|(_s[j]=='*');
  }
  for(long i = 0, j = -1; i<h1; )
    if(j==-1 || d1[i]==d1[j])
      fail[++i] = ++j;
    else
      j = fail[j];
  for(int j = 0; j<=w0-w1; j++)
    for(int i0 = 0, i1 = 0; i0<h0; ) {
      if(d0[j][i0]==d1[i1]) {
        i0++;
        i1++;
        if(i1==h1)
          return 1;
      } else if(i1)
        i1 = fail[i1];
      else
        i0++;
      if(h1-i1>h0-i0)
        break;
    }
  return 0;
}

int main() {
  for(int kase = 1; scanf("%d%d%d%d%d", &h0, &w0, &n, &h1, &w1), n; kase++) {
    if(h0<h1 || w0<w1) {
      printf("Case %d: %d\n", kase, 0);
      continue;
    }
    bazinga0();
    int res = 0;
    while(n--)
      res += bazinga1();
    printf("Case %d: %d\n", kase, res);
  }
  return 0;
}
