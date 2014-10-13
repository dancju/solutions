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

const int N = 100000, M = 200000;
char s[N+1];
size_t v0[M], v1[M], cnt[N], topo[M];
SAM<26, M> sam;

int main() {
  scanf("%s", s);
  size_t len = strlen(s);
  for(char *i = s; *i; i++)
    sam.insert(*i-'a');
  for(long i = 0; i<sam.size(); i++)
    cnt[sam[i].val]++;
  for(long i = 0; i<len; i++)
    cnt[i+1] += cnt[i];
  for(long i = sam.size()-1; i>=0; i--)
    topo[--cnt[sam[i].val]] = i;
  for(long p = 0; p<sam.size(); p++)
    v0[p] = sam[p].val;
  while(~scanf("%s", s)) {
    memset(v1, 0, sizeof(v1));
    for(size_t i = 0, t = 0, p = 0; s[i]; )
      if(sam[p].trans[s[i]-'a']) {
        p = sam[p].trans[s[i]-'a']-sam.begin();
        i++;
        maximize(v1[p], ++t);
      } else if(p) {
        p = sam[p].pare-sam.begin();
        t = sam[p].val;
      } else
        i++;
    for(size_t *i = topo+sam.size()-1; i>=topo; i--) {
      if(*i)
        maximize(v1[sam[*i].pare-sam.begin()], v1[*i]);
      minimize(v0[*i], v1[*i]);
    }
  }
  size_t res = 0;
  for(long p = 0; p<sam.size(); p++)
    maximize(res, v0[p]);
  printf("%ld\n", res);
  return 0;
}
