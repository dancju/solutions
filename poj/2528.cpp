#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<vector>
#define lowBit(x) ((x)&-(x))
#define unify(c) c.resize(unique(c.begin(), c.end())-c.begin())

using namespace std;

int n;
int lo[10000], hi[10000];
inline void discretization() {
  vector<int> bin;
  scanf("%d", &n);
  bin.reserve(n<<2);
  for(int i = 0; i<n; i++) {
    scanf("%d%d", lo+i, hi+i);
    bin.push_back(lo[i]);
    bin.push_back(++hi[i]);
  }
  sort(bin.begin(), bin.end());
  unify(bin);
  for(int i = 0; i<n; i++) {
    lo[i] = lower_bound(bin.begin(), bin.end(), lo[i])-bin.begin();
    hi[i] = lower_bound(bin.begin(), bin.end(), hi[i])-bin.begin();
  }
}

const int N = 1<<16;
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

int tree[N<<1];

void update(int _, size_t lo, size_t hi, int val) {
  if(lo<=left(_) && right(_)<=hi) {
    tree[_] = val;
    return;
  }
  if(tree[_]+1) {
    tree[_<<1] = tree[_<<1|1] = tree[_];
    tree[_] = -1;
  }
  if(lo<right(_<<1))
    update(_<<1, lo, hi, val);
  if(hi>right(_<<1))
    update(_<<1|1, lo, hi, val);
}

bitset<10000> s;

void query(int _, size_t lo, size_t hi) {
  if(tree[_]!=-1) {
    s.set(tree[_]);
    return;
  }
  if(_<N) {
    query(_<<1, lo, hi);
    query(_<<1|1, lo, hi);
  }
}

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    discretization();
    memset(tree, -1, sizeof tree);
    for(int i = 0; i<n; i++)
      update(1, lo[i], hi[i], i);
    s.reset();
    query(1, 0, 20000);
    printf("%zu\n", s.count());
  }
  return 0;
}