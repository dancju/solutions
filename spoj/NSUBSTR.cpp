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

const size_t N = 250000, M = 0x60000;
SAM<26, M> sam;
char raw[N+1];
int val[N+1], topo[M], cnt[M], f[N+1];

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  gets(raw);
  int len = (int)strlen(raw);
  for(char *i = raw; *i; i++)
    sam.insert(*i-'a');
  for(SAM<26, M>::iterator i = sam.begin(); i!=sam.end(); i++)
    val[i->val]++;
  for(long i = 0; i<len; i++)
    val[i+1] += val[i];
  for(int i = 0; i<sam.size(); i++)
    topo[--val[sam[i].val]] = i;
  for(int i = 0, p = 0; sam[i]; i++)
    cnt[p = (int)(sam[p].trans[raw[i]]-sam.begin())]++;
  for(int *i = topo+sam.size()-1; i>topo; i--) {
    maximize(f[sam[*i].val], cnt[*i]);
    cnt[sam[*i].pare-sam.begin()] += cnt[*i];
  }
  for(long i = len-1; i>=0; i--)
    maximize(f[i], f[i+1]);
  for(long i = 1; i<=len; i++)
    printf("%d\n", f[i]);
  return 0;
}
