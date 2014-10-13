#include<algorithm>
#include<climits>
#include<cstdio>

using namespace std;

template<class T> inline T maximize(T& a, const T& b) { return a=a<b?b:a; }

const size_t N = 1<<16;
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

int sum[N<<1], ma[N<<1], lma[N<<1], rma[N<<1];

int query(int lo, int hi, int& t0, int& t1, int _ = 1) {
  if(lo<=left(_) && right(_)<=hi) {
    maximize(t1, max(t0+lma[_], ma[_]));
    t0 = max(t0+sum[_], rma[_]);
    return t1;
  }
  if(lo<right(_<<1))
    query(lo, hi, t0, t1, _<<1);
  if(hi>right(_<<1))
    query(lo, hi, t0, t1, _<<1|1);
  return t1;
}

inline int query(int lo, int hi) {
  int t = 0, res = INT_MIN;
  query(lo, hi, t, res);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = N; i < N+n; i++) {
    scanf("%d", sum+i);
    lma[i] = rma[i] = ma[i] = sum[i];
  }
  for(int i = N-1; i; i--) {
    sum[i] = sum[i<<1]+sum[i<<1|1];
    ma[i] = max(max(ma[i<<1], ma[i<<1|1]), rma[i<<1]+lma[i<<1|1]);
    lma[i] = max(lma[i<<1], sum[i<<1]+lma[i<<1|1]);
    rma[i] = max(rma[i<<1|1], sum[i<<1|1]+rma[i<<1]);
  }
  scanf("%d", &n);
  while(n--) {
    int lo, hi;
    scanf("%d%d", &lo, &hi);
    printf("%d\n", query(--lo, hi));
  }
  return 0;
}