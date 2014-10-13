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
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define endl '\n'

const long double PI = acos(-1.L);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char uint8_t;
using namespace std;
template<class T> T maximize(T &a, const T &b) { return a = max(a, b); }
template<class T> T minimize(T &a, const T &b) { return a = min(a, b); }

template<uint8_t alphabet> class SuffixAutomaton {
  struct State {
    size_t val, pare, trans[alphabet];
    State(size_t val) : val(val) { memset(trans, 0, sizeof trans); }
  };
  size_t last;
  vector<State> pool;
public:
  SuffixAutomaton() : last(0) {
    pool.push_back(State(0));
    pool[0].pare = -1;
  }
  SuffixAutomaton(size_t n) : last(0) {
    assert(n>0);
    pool.reserve(n<<1);
    pool.push_back(State(0));
    pool[0].pare = -1;
  }
  inline void insert(uint8_t x) {
    assert(0<=x && x<alphabet);
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
    assert(0<=x && x<size() && 0<=y && y<alphabet);
    return pool[x].trans[y];
  }
  inline void print(char i2c(uint8_t)) const {
    printf("    ");
    for(uint8_t j = 0; j<alphabet; j++)
      printf("%2c", i2c(j));
    puts("");
    for(size_t i = 0; i<size(); i++) {
      printf("%2ld |", i);
      for(uint8_t j = 0; j<alphabet; j++)
        if(trans(i, j))
          printf("%2ld", trans(i, j));
        else
          printf("  ");
      printf(" |%2ld", pare(i));
      puts("");
    }
  }
};

char s[100001];

int main() {
  SuffixAutomaton<26> sam;
  size_t res = 0, _ = 0;
  scanf("%s", s);
  for(char *i = s; *i; i++)
    sam.insert(*i-'a');
  scanf("%s", s);
  for(size_t p = 0, i = 0; s[i]; maximize(res, _))
    if(sam.trans(p, s[i]-'a')) {
      p = sam.trans(p, s[i]-'a');
      i++;
      _++;
    } else if(p) {
      p = sam.pare(p);
      _ = sam.val(p);
    } else
      i++;
  printf("%ld\n", res);
  return 0;
}
