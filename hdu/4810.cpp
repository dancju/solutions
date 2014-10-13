#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int MOD = 1e6+3;

template<class T> void cut(T& x) { if(x>=MOD) x -= MOD; }

int pascal[1001][1001];
int n, a[1000], b[32];

int main() {
  for(int i = 0; i<=1000; i++) {
    pascal[i][0] = pascal[i][i] = 1;
    for(int j = 1; j<i; j++) {
      pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
      cut(pascal[i][j]);
    }
  }
  while(~scanf("%d", &n)) {
    memset(b, 0, sizeof b);
    for(int i = 0; i<n; i++) {
      scanf("%d", a+i);
      for(int j = 0; j<32; j++)
        if(a[i]&(1<<j))
          b[j]++;
    }
    for(int k = 1; k<=n; k++) {
      int res = 0;
      for(int j = 0; j<32; j++) {
        for(int x = max(1, (k-n+b[j])|1); x<=k && x<=b[j]; x+=2) {
          long long t = pascal[b[j]][x]*pascal[n-b[j]][k-x];
          t %= MOD;
          for(int i = 0; i<j; i++) {
            t <<= 1;
            cut(t);
          }
          res = t+res;
          cut(res);
        }
      }
      printf(k==1 ? "%d" : " %d", res);
    }
    puts("");
  }
  return 0;
}
