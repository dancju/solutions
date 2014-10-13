/*
 ID: danny_c1
 PROG: theme
 LANG: C++
 */
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

template<uint8_t sigma> class SuffixAutomaton {
  struct State {
    size_t val, pare, trans[sigma];
    State(size_t val) : val(val) { memset(trans, 0, sizeof trans); }
  };
  size_t last;
  vector<State> pool;
public:
  SuffixAutomaton() : last(0) {
    pool.push_back(State(0));
    pool[0].pare = -1;
  }
  inline void clear() {
    last = 0;
    pool.clear();
    pool.push_back(State(0));
    pool[0].pare = -1;
  }
  inline void reserve(size_t n) {
    assert(n>=0);
    pool.reserve(n<<1);
  }
  inline void insert(uint8_t x) {
    assert(0<=x && x<sigma);
    size_t p = last, np = pool.size();
    pool.push_back(State(pool[p].val+1));
    for(; ~p && !pool[p].trans[x]; p = pool[p].pare)
      pool[p].trans[x] = np;
    size_t q = pool[p].trans[x];
    if(!~p)
      pool[np].pare = 0;
    else if(pool[p].val+1 == pool[q].val)
      pool[np].pare = q;
    else {
      size_t nq = pool.size();
      pool.push_back(State(pool[p].val+1));
      memcpy(pool[nq].trans, pool[q].trans, sizeof pool[q].trans);
      pool[nq].pare = pool[q].pare;
      pool[q].pare = nq;
      pool[np].pare = nq;
      for(; ~p && pool[p].trans[x]==q; p = pool[p].pare)
        pool[p].trans[x] = nq;
    }
    last = np;
    assert(last);
  }
  inline size_t size() const { return pool.size(); }
  inline size_t pare(size_t x) const {
    assert(0<=x && x<size());
    return pool[x].pare;
  }
  inline size_t val(size_t x) const {
    assert(0<=x && x<size());
    return pool[x].val;
  }
  inline size_t trans(size_t x, uint8_t y) const {
    assert(0<=x && x<size() && 0<=y && y<sigma);
    return pool[x].trans[y];
  }
  inline void print(char i2c(uint8_t)) const {
    printf("    ");
    for(uint8_t j = 0; j<sigma; j++)
      printf("%2c", i2c(j));
    puts("");
    for(size_t i = 0; i<size(); i++) {
      printf("%2ld |", i);
      for(uint8_t j = 0; j<sigma; j++)
        if(trans(i, j))
          printf("%2ld", trans(i, j));
        else
          printf("  ");
      printf(" |%2ld", val(i));
      puts("");
    }
  }
};

const int N = 20000, M = 25000;
int n;
short raw[N];
SuffixAutomaton<175> sam;

inline void bazinga0() {
  scanf("%d", &n);
  int i0, i1;
  n--;
  sam.clear();
  sam.reserve(n);
  scanf("%d", &i1);
  for(int i = 0; i<n; i++) {
    i0 = i1;
    scanf("%d", &i1);
    raw[i] = i1-i0+87;
    sam.insert(raw[i]);
  }
}

unsigned short val[N], topo[M];
short first[M], last[M];

inline void bazinga1() {
  memset(val, 0, sizeof val);
  for(int i = 0; i<sam.size(); i++)
    val[sam.val(i)]++;
  for(short i = 1; i<=n; i++)
    val[i] += val[i-1];
  for(int i = 0; i<sam.size(); i++)
    topo[--val[sam.val(i)]] = i;
  memset(first, 0x7f, sizeof first);
  memset(last, 0, sizeof last);
  memset(first, 0x7f, sam.size()*sizeof(short));
  for(long p = 0, i = 0; i<n; i++) {
    p = sam.trans(p, raw[i]);
    first[p] = last[p] = i+1;
  }
  for(long j = sam.size()-1; j; j--) {
    int i = topo[j];
    minimize(first[sam.pare(i)], first[i]);
    maximize(last[sam.pare(i)], last[i]);
  }
}

int res;

inline void bazinga2() {
  res = -1;
  for(int i = 1; i<sam.size(); i++)
    if(sam.val(i)>3 && first[i]+sam.val(i)<last[i])
      maximize(res, (int)sam.val(i));
}

int main() {
  freopen("theme.in", "r", stdin);
  freopen("theme.out", "w", stdout);
  bazinga0();
  bazinga1();
  bazinga2();
  printf("%d\n", res+1);
  return 0;
}
