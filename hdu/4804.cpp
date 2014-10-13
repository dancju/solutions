#include<cstdio>
#include<cstring>

using namespace std;
const int MOD = 1e9+7;

int n, m, lo, hi;
short a[101];
int f[4][1<<10][21];

void cut(int& x) { if(x>=MOD) x -= MOD; }

inline void bazinga0() {
  memset(a, 0, sizeof a);
  a[0] = (1<<m)-1;
  for(int i = 1; i<=n; i++) {
    getchar();
    for(int j = 0; j<m; j++) {
      char c = getchar();
      if(c=='1')
        a[i] ^= 1<<j;
    }
  }
}

inline void bazinga1() {
  for(int j = 0; j<m; j++) {
    memset(f[j&3], 0, sizeof f[0]);
    f[j&3][(1<<(j+1))-1][0] = 1;
  }
  for(int i = 1; i<=n; i++)
    for(int j = 0; j<m; j++) {
      int _ = i*m+j;
      memset(f[_&3], 0, sizeof f[0]);
      for(int s = 0; s<1<<m; s++)
        for(int k = 0; k<=hi; k++)
          if(a[i]&(1<<j)) {                                  // 可放
            if(s&(1<<j)) {                                   //   放了
              if(k)                                          //     1x1
                f[_&3][s][k] += f[(_-1)&3][s][k-1];
              f[_&3][s][k] += f[(_-1)&3][s^(1<<j)][k];       //     2x1
              cut(f[_&3][s][k]);
              if(j && (a[i]&(1<<(j-1))) && (s&(1<<(j-1)))) { //     1x2
                f[_&3][s][k] += f[(_-2)&3][s][k];
                cut(f[_&3][s][k]);
              }
            } else {                                         //   沒放
              f[_&3][s][k] = f[(_-1)&3][s^(1<<j)][k];
            }
          } else if(s&(1<<j)) {                              // 不可放
            f[_&3][s][k] = f[(_-1)&3][s][k];
          }
    }
}

int main() {
  while(~scanf("%d%d%d%d", &n, &m, &lo, &hi)) {
    bazinga0();
    bazinga1();
    int res = 0;
    for(int i = lo; i<=hi; i++) {
      res += f[(n*m+m-1)&3][(1<<m)-1][i];
      cut(res);
    }
    printf("%d\n", res);
  }
  return 0;
}