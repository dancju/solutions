#include<algorithm>
#include<cstdio>

using namespace std;

const size_t N = 1<<16;
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

unsigned short vm[N<<1], vl[N<<1], vr[N<<1];

void update(int lo, int hi, bool val, int _ = 1) {
  if(lo<=left(_) && right(_)<=hi) {
    if(val)
      vm[_] = vl[_] = vr[_] = length(_);
    else
      vm[_] = vl[_] = vr[_] = 0;
    return;
  }
  if(!vm[_])
    vm[_<<1] = vl[_<<1] = vr[_<<1] = vm[_<<1|1] = vl[_<<1|1] = vr[_<<1|1] = 0;
  else if(vm[_]==length(_))
    vm[_<<1] = vl[_<<1] = vr[_<<1] = vm[_<<1|1] = vl[_<<1|1] = vr[_<<1|1] = length(_<<1);
  int mid = right(_<<1);
  if(lo<mid)
    update(lo, hi, val, _<<1);
  if(hi>mid)
    update(lo, hi, val, _<<1|1);
  vl[_] = vl[_<<1]+(vm[_<<1]==length(_<<1) ? vl[_<<1|1] : 0);
  vr[_] = vr[_<<1|1]+(vm[_<<1|1]==length(_<<1) ? vr[_<<1] : 0);
  vm[_] = max((int)max(vm[_<<1], vm[_<<1|1]), vr[_<<1]+vl[_<<1|1]);
}

int query(int len, int _ = 1) {
  if(vm[_]<len)
    return -1;
  if(vl[_]>=len)
    return left(_);
  int res = query(len, _<<1);
  if(~res)
    return res;
  if(vr[_<<1]+vl[_<<1|1]>=len)
    return right(_<<1)-vr[_<<1];
  return query(len, _<<1|1);
}

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  update(0, n, 1);
  while(m--) {
    char o = getchar();
    int lo, len;
    if(o=='1') {
      scanf("%d\n", &len);
      lo = query(len);
      printf("%d\n", lo+1);
      if(~lo)
        update(lo, lo+len, 0);
    } else {
      scanf("%d%d\n", &lo, &len);
      lo -= 1;
      update(lo, lo+len, 1);
    }
  }
  return 0;
}