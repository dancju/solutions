#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<climits>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define endl '\n'
#define maximize(a,b) (a=(a<b?b:a))
#define minimize(a,b) (a=(a<b?a:b))
#define popCount __builtin_popcountll
#define lowBit(x) (x&-x)
#define highBit(x) (1ULL<<(63-__builtin_clzll(x)))
#define ceil(a,b) ((a-1)/b+1)
#define gcd __gcd
#define lcm(a,b) (a/gcd(a,b)*b)

using namespace std;

template<class T> class FenwickTree {
#define lowBit(x) (x&-x)
  size_t n;
  T *val;
public:
  FenwickTree(size_t n) : n(n), val(new T[n+1]()) {}
  ~FenwickTree() { delete[] val; }
  template<class I> FenwickTree(I lo, I hi) : n(hi-lo+1), val(new T[n+1]()) {
    memcpy(val, lo, sizeof(T)*(hi-lo));
    for(size_t i = 2; i<=n; i++)
      val[i] += val[i-lowBit(i)];
  }
  inline void clear() { memset(val, 0, sizeof(T)*(n+1)); }
  inline void modify(size_t x, T delta) {
    assert(x && x<=n);
    while(x <= n) {
      val[x] += delta;
      x += lowBit(x);
    }
  }
  inline T sum(size_t x) {
    assert(x && x<=n);
    T result = 0;
    while(x) {
      result += val[x];
      x -= lowBit(x);
    }
    return result;
  }
  inline T sum(size_t from, size_t to) {
    assert(from && from<=to && to<=n);
    return sum(to)-sum(from-1);
  }
};

int main() {
  int n;
  FenwickTree<short> ft(5000);
  while(~scanf("%d", &n)) {
    int res0 = 0, res1 = 0, res2 = 0;
    ft.clear();
    for(int i = 0; i<n; i++) {
      int _;
      scanf("%d", &_);
      res0 += i-ft.sum(_+1);
      res1 += n-_-_-1;
      minimize(res2, res1);
      ft.modify(_+1, 1);
    }
    printf("%d\n", res0+res2);
  }
  return 0;
}