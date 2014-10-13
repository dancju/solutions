#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

template<class T> inline T maximize(T& a, const T& b) { return a=a<b?b:a; }

const size_t N = 1<<14;
long long d[N<<1], dl[N<<1], dm[N<<1], dr[N<<1];
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

int sum[N<<1], ma[N<<1], lma[N<<1], rma[N<<1];

int querysum(int lo, int hi, int _ = 1) {
  if(lo>=hi)
    return 0;
  if(lo<=left(_) && right(_)<=hi)
    return sum[_];
  int res = 0;
  if(lo<right(_<<1))
    res += querysum(lo, hi, _<<1);
  if(hi>right(_<<1))
    res += querysum(lo, hi, _<<1|1);
  return res;
}

int querylma(int lo, int hi, int _ = 1) {
  if(lo>=hi)
    return 0;
  if(lo<=left(_) && right(_)<=hi)
    return lma[_];
  if(hi<=right(_<<1))
    return querylma(lo, hi, _<<1);
  if(lo>=right(_<<1))
    return querylma(lo, hi, _<<1|1);
  return
    max(querylma(lo, hi, _<<1),
        querysum(lo, hi, _<<1)+querylma(lo, hi, _<<1|1));
}

int queryrma(int lo, int hi, int _ = 1) {
  if(lo>=hi)
    return 0;
  if(lo<=left(_) && right(_)<=hi)
    return rma[_];
  if(hi<=right(_<<1))
    return queryrma(lo, hi, _<<1);
  if(lo>=right(_<<1))
    return queryrma(lo, hi, _<<1|1);
  return
    max(queryrma(lo, hi, _<<1|1),
        querysum(lo, hi, _<<1|1)+queryrma(lo, hi, _<<1));
}

int querymax(int lo, int hi, int _ = 1) {
  if(lo>=hi)
    return 0;
  if(lo<=left(_) && right(_)<=hi)
    return ma[_];
  if(hi<=right(_<<1))
    return querymax(lo, hi, _<<1);
  if(lo>=right(_<<1))
    return querymax(lo, hi, _<<1|1);
  return
    max(
        max(querymax(lo, hi, _<<1|1), querymax(lo, hi, _<<1)),
        queryrma(lo, hi, _<<1)+querylma(lo, hi, _<<1|1));
}

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    int n;
    scanf("%d", &n);
    memset(sum, 0, sizeof sum);
    memset(ma, 0, sizeof ma);
    memset(lma, 0, sizeof lma);
    memset(rma, 0, sizeof rma);
    for(int i = N; i < N+n; i++) {
      scanf("%d", sum+i);
      ma[i] = lma[i] = rma[i] = sum[i];
    }
    for(int i = N-1; i; i--) {
      int l = i<<1, r = i<<1|1;
      sum[i] = sum[l]+sum[r];
      ma[i] = max(max(ma[l], ma[r]), rma[l]+lma[r]);
      lma[i] = max(lma[l], sum[l]+lma[r]);
      rma[i] = max(rma[r], rma[l]+sum[r]);
    }
    scanf("%d", &n);
    while(n--) {
      int lo0, hi0, lo1, hi1;
      scanf("%d%d%d%d", &lo0, &hi0, &lo1, &hi1);
      lo0--;
      lo1--;
      if(hi0<=lo1)
        printf(
            "%d\n",
            queryrma(lo0, hi0)+querysum(hi0, lo1)+querylma(lo1, hi1));
      else
        printf(
            "%d\n",
            max(
                querymax(lo1, hi0),
                max(
                    queryrma(lo0, lo1)+querylma(lo1, hi1),
                    queryrma(lo0, hi0)+querylma(hi0, hi1))));
    }
  }
  return 0;
}