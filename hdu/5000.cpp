#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
const int MOD = 1000000007;

int a[2001];
int f[2001][2001];

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
      scanf("%d", a+i);
      a[i] += a[i-1];
    }
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for(int i = 1; i<=n; i++)
      for(int j = 0; j<=a[i]; j++)
        for(int k = 0; k<=min(j, a[i]-a[i-1]); k++)
          f[i][j] = ((long long)f[i][j]+f[i-1][j-k])%MOD;
    printf("%d\n", f[n][a[n]/2+(a[n]&1)]);
  }
  return 0;
}
