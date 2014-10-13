#include<bitset>
#include<cstdio>

using namespace std;

short n, x, y;
int a[15], s[1<<15];
bitset<1<<15> f[101];

int main() {
  for(short iCase = 1; scanf("%hd", &n), n; iCase++) {
    scanf("%hd%hd", &x, &y);
    if(x>y)
      swap(x, y);
    for(short i = 1; i<=x; i++)
      f[i].reset();
    int _t = 0;
    for(short i = 0; i < n; i++) {
      scanf("%d", a+i);
      _t += a[i];
      for(short k = 1; k*k<=a[i]; k++)
        if(a[i]%k==0)
          f[k].set(1<<i);
    }
    if(_t != x*y) {
      printf("Case %d: No\n", iCase);
      continue;
    }
    for(int i = 0; i < (1<<n); i++) {
      s[i] = 0;
      for(short j = 0; j < n; j++)
        if(i&(1<<j))
          s[i] += a[j];
    }
    for(short i = 1; i<=x; i++)
      for(int k = 1; k < (1<<n); k++)
        if(s[k]%i==0 && i*i<=s[k]) {
          short j = s[k]/i;
          if(j>y)
            continue;
          for(short k0 = (k-1)&k; k0; k0 = (k0-1)&k) {
            short k1 = k^k0;
            if((s[k0]%i==0 && f[i*i<=s[k0]?i:s[k0]/i][k0] && f[i*i<=s[k1]?i:s[k1]/i][k1]) ||
                (s[k0]%j==0 && f[j*j<=s[k0]?j:s[k0]/j][k0] && f[j*j<=s[k1]?j:s[k1]/j][k1]))
              f[i][k] = 1;
          }
        }
    printf("Case %d: %s\n", iCase, f[x][(1<<n)-1]?"Yes":"No");
  }
  return 0;
}
