#include<cstdio>
#define highBit(x) (1ULL<<(63-__builtin_clzll(x)))

int f[100001];

int main() {
  int n;
  while(~scanf("%d", &n)) {
    f[0] = 0;
    for(int i = n; i>0; ) {
      int _ = highBit(i)*2-i-2;
      for(int j = _+1; j<=i; j++)
        f[j] = _+1+i-j;
      i = _;
    }
#ifndef ONLINE_JUDGE
    printf("%lldd\n", (long long)n*(n+1));
#else
    printf("%I64d\n", (long long)n*(n+1));
#endif
    for(int i = 0; i<=n; i++) {
      int _;
      scanf("%d", &_);
      if(i)
        putchar(' ');
      printf("%d", f[_]);
    }
    puts("");
  }
  return 0;
}