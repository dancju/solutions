#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

const size_t N = 1<<17;
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

long long sum[N<<1];

void update(int lo, int hi, int _ = 1) {
  if(sum[_]==length(_))
    return;
  if(N<=_) {
    sum[_] = sqrt(sum[_]);
    return;
  }
  if(lo<right(_<<1))
    update(lo, hi, _<<1);
  if(hi>right(_<<1))
    update(lo, hi, _<<1|1);
  sum[_] = sum[_<<1]+sum[_<<1|1];
}

inline long long query(int lo, int hi, int _ = 1) {
  long long res = 0;
  for(lo += N-1, hi += N; lo^hi^1; lo>>=1, hi>>=1) {
    if(~lo&1)
      res += sum[lo^1];
    if(hi&1)
      res += sum[hi^1];
  }
  return res;
}

int main() {
  int n;
  for(int iCase = 1; ~scanf("%d", &n); iCase++) {
    printf("Case #%d:\n", iCase);
    memset(sum, 0, sizeof sum);
    for(int i = N; i<N+n; i++)
      scanf("%lld", sum+i);
    for(int i = N-1; i; i--)
      sum[i] = sum[i<<1]+sum[i<<1|1];
    scanf("%d", &n);
    while(n--) {
      char o;
      int lo, hi;
      scanf("\n%c%d%d", &o, &lo, &hi);
      if(lo>hi)
        swap(lo, hi);
      --lo;
      if(o=='0')
        update(lo, hi);
      else
        printf("%lld\n", query(lo, hi));
    }
    putchar('\n');
  }
  return 0;
}