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

inline uint8_t c2i(char c) {
  if('a'<=c && c<='z')
    return c-'a';
  assert('A'<=c && c<='Z');
  return c-'A'+26;
}

const int N = 100000, M = 0x26000;
int k, n;
char s[N+1];
SAM<52, M> sam;

inline void bazinga0() {
  scanf("%s", s);
  n = (int)strlen(s);
  sam.clear();
  for(char *i = s; *i; i++) {
    *i = c2i(*i);
    sam.insert(*i);
  }
}

int val[N+1], topo[M], c[M];

inline void bazinga1() {
  memset(val, 0, sizeof val);
  for(SAM<52, M>::iterator i = sam.begin(); i!=sam.end(); i++)
    val[i->val]++;
  for(int i = 1; i<=n; i++)
    val[i] += val[i-1];
  for(SAM<52, M>::iterator i = sam.begin(); i!=sam.end(); i++)
    topo[--val[i->val]] = (int)(i-sam.begin());
  memset(c, 0, sizeof c);
  for(int p = 0, i = 0; i<n; i++)
    c[p = (int)(sam[p].trans[s[i]]-sam.begin())]++;
  for(int *p = topo+sam.size()-1; *p; p--)
    c[sam[*p].pare-sam.begin()] += c[*p];
}

int t[M];

inline void bazinga2() {
  long long res = 0;
  scanf("%s", s);
  size_t p = 0, l = 0;
  memset(t, 0, sizeof t);
  for(char *i = s; *i; ) {
    SAM<52, M>::iterator _ = sam[p].trans[c2i(*i)];
    if(_) {
      p = _-sam.begin();
      l++;
      i++;
      if(l>=k) {
        res += ((long long)l-max(k-1, (int)sam[p].pare->val))*c[p];
        t[_->pare-sam.begin()]++;
      }
    } else if(p) {
      p = sam[p].pare-sam.begin();
      l = sam[p].val;
    } else
      i++;
  }
  for(int *p = topo+sam.size()-1; *p; p--) {
    t[sam[*p].pare-sam.begin()] += t[*p];
    if(sam[*p].val>=k)
      res += ((long long)sam[*p].val-max(k-1, (int)sam[*p].pare->val))*c[*p]*t[*p];
  }
  cout<<res<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  while(scanf("%d", &k), k) {
    bazinga0();
    bazinga1();
    bazinga2();
  }
  return 0;
}
