#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define endl '\n'

const long double PI = acos(-1.L);
using namespace std;
template<class T> T maximize(T &a, const T &b) { return a = max(a, b); }
template<class T> T minimize(T &a, const T &b) { return a = min(a, b); }

typedef unsigned char uint8_t;

template<uint8_t SIGMA, size_t CAPACITY> class SAM {
  struct State {
    size_t val;
    State *pare, *trans[SIGMA];
  } pool[CAPACITY];
  State *_end, *last;
public:
  typedef const State* iterator;
  SAM() : _end(pool+1), last(pool) { memset(&pool[0], 0, sizeof(State)); }
  inline void clear() {
    _end = pool+1;
    last = pool;
    memset(&pool[0], 0, sizeof(State));
  }
  inline void insert(uint8_t x) {
    assert(0<=x && x<SIGMA);
    State *p = last, *np = _end++;
    assert(_end<=pool+CAPACITY);
    np->val = p->val+1;
    memset(np->trans, 0, sizeof np->trans);
    for(; p && p->trans[x]==0; p = p->pare)
      p->trans[x] = np;
    last = np;
    if(p==NULL) {
      np->pare = pool;
      return;
    }
    State *q = p->trans[x];
    if(p->val+1 == q->val)
      np->pare = q;
    else {
      State *nq = _end++;
      assert(_end<=pool+CAPACITY);
      nq->val = p->val+1;
      memcpy(nq->trans, q->trans, sizeof q->trans);
      nq->pare = q->pare;
      q->pare = nq;
      np->pare = nq;
      for(; p && p->trans[x]==q; p = p->pare)
        p->trans[x] = nq;
    }
  }
  inline iterator begin() const { return pool; }
  inline iterator end() const { return _end; }
  inline size_t size() const { return _end-pool; }
  inline const State& operator[](size_t x) const { return pool[x]; }
  inline void print(char i2c(uint8_t)) const {
    printf("    ");
    for(uint8_t j = 0; j<SIGMA; j++)
      printf("%3c", i2c(j));
    puts("");
    for(iterator i = pool; i<_end; i++) {
      printf("%2ld |", i-pool);
      for(uint8_t j = 0; j<SIGMA; j++)
        if(i->trans[j])
          printf("%3ld", i->trans[j]-pool);
        else
          printf("   ");
      printf(" |%3ld\n", i->val);
    }
  }
};

const int N = 20000, M = 33529;
int n;
short raw[N];
SAM<175, M> sam;

inline void bazinga0() {
  int i0, i1;
  n--;
  sam.clear();
  scanf("%d", &i1);
  for(int i = 0; i<n; i++) {
    i0 = i1;
    scanf("%d", &i1);
    sam.insert(raw[i] = i1-i0+87);
  }
}

unsigned short val[N], topo[M];
short first[M], last[M];

inline void bazinga1() {
  memset(val, 0, sizeof val);
  for(SAM<175, M>::iterator i = sam.begin(); i!=sam.end(); i++)
    val[i->val]++;
  for(short i = 1; i<=n; i++)
    val[i] += val[i-1];
  for(SAM<175, M>::iterator i = sam.begin(); i!=sam.end(); i++)
    topo[--val[i->val]] = i-sam.begin();
  memset(first, 0x7f, sizeof first);
  memset(last, 0, sizeof last);
  for(long p = 0, i = 0; i<n; i++) {
    p = sam[p].trans[raw[i]]-sam.begin();
    first[p] = last[p] = i+1;
  }
  for(long j = sam.size()-1; j; j--) {
    int i = topo[j];
    minimize(first[sam[i].pare-sam.begin()], first[i]);
    maximize(last[sam[i].pare-sam.begin()], last[i]);
  }
}

int res;

inline void bazinga2() {
  res = -1;
  for(int i = 1; i<sam.size(); i++)
    if(first[i]+sam[i].val<last[i])
      maximize(res, (int)sam[i].val);
}

int main() {
  while(scanf("%d", &n), n) {
    bazinga0();
    bazinga1();
    bazinga2();
    if(res>3)
      printf("%d\n", res+1);
    else
      puts("0");
  }
  return 0;
}
