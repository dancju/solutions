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

int n;
char d0[10][21];
short d1[10];

inline void bazinga0() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%s", d0[i]);
    d1[i] = strlen(d0[i]);
  }
}

short d2[10][10];
int dest;

inline void bazinga1() {
  dest = 0;
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
      if(i!=j)
        for(int k = 0; k<=d1[i]; k++)
          if(memcmp(d0[i]+k, d0[j], min(d1[i]-k, (int)d1[j]))==0) {
            if(d1[i]>=k+d1[j] && !(k==0 && d1[i]==d1[j] && i<j))
              dest ^= 1<<j;
            else
              d2[i][j] = max((int)d1[i], k+d1[j])-d1[i];
            break;
          }
}

int res;
int d3[1<<10][10];

void bazinga21(int s, int last) {
  if(s==dest) {
    minimize(res, d3[s][last]);
    return;
  }
  for(int i = 0; i<n; i++)
    if(s&(1<<i) && d3[s^(1<<i)][i]>d3[s][last]+d2[last][i]) {
      d3[s^(1<<i)][i] = d3[s][last]+d2[last][i];
      bazinga21(s^(1<<i), i);
    }
}

inline void bazinga20() {
  memset(d3, 0x7f, sizeof d3);
  res = INT_MAX;
  for(int i = 0; i<n; i++) {
    d3[((1<<n)-1)^(1<<i)][i] = d1[i];
    bazinga21(((1<<n)-1)^(1<<i), i);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    bazinga0();
    bazinga1();
    bazinga20();
    printf("%d\n", res);
  }
  return 0;
}
