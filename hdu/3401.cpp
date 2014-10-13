#include<cstdio>
#include<deque>

using namespace std;

template<class T> inline T maximize(T& a, const T& b) { return a=a<b?b:a; }

const int N = 2000;

int iP[N+1], oP[N+1], iS[N+1], oS[N+1], f[N+1][N+1];
deque<int> deq;

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    int n, m, thres;
    scanf("%d%d%d", &n, &m, &thres);
    for(int i = 1; i<=n; i++)
      scanf("%d%d%d%d", iP+i, oP+i, iS+i, oS+i);
    memset(f, 0x80, sizeof f);
    for(int i = 1; i<=n; i++)
      for(int j = 0; j<=iS[i]; j++)
        f[i][j] = -j*iP[i];
    for(int i = 2; i<=n; i++)
      for(int j = 0; j<=m; j++)
        maximize(f[i][j], f[i-1][j]);
    for(int i = thres+2; i<=n; ++i) {
      int _i = i-thres-1;
      for(int j = 0; j<=m; j++)
        maximize(f[i][j], f[i-1][j]);
      deq.clear();
      for(int j = 0; j<=m; j++) {
        #define fun0(x) f[_i][x]+x*iP[i]
        while(deq.size() && fun0(j)>=fun0(deq.back()))
          deq.pop_back();
        while(deq.size() && deq.front()<j-iS[i])
          deq.pop_front();
        deq.push_back(j);
        maximize(f[i][j], -j*iP[i]+fun0(deq.front()));
      }
      deq.clear();
      for(int j = m; j>=0; j--) {
        #define fun1(x) f[_i][x]+x*oP[i]
        while(deq.size() && fun1(j)>=fun1(deq.back()))
          deq.pop_back();
        while(deq.size() && deq.front()>j+oS[i])
          deq.pop_front();
        deq.push_back(j);
        maximize(f[i][j], -j*oP[i]+fun1(deq.front()));
      }
    }
    int res = 0;
    for(int i = 0; i<=m; i++)
      maximize(res, f[n][i]);
    printf("%d\n", res);
  }
  return 0;
}