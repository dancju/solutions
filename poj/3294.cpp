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

const int N = 1005*100+100;

int from0[N<<1];
char from1[N<<1];
bool from2[N<<1];

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
  inline void clear() {
    last = 0;
    pool.clear();
    pool.push_back(State(0));
    pool[0].pare = -1L;
    from2[0] = 1;
  }
  inline void reserve(size_t n) {
    assert(n>0);
    pool.reserve(n<<1);
  }
  inline void insert(uint8_t x) {
    assert(0<=x && x<alphabet);
    size_t p = last, np = pool.size();
    pool.push_back(State(pool[p].val+1));
    from0[np] = p;
    from1[np] = x;
    from2[np] = from2[p] && x!=26;
    for(; ~p && !pool[p].trans[x]; p = pool[p].pare)
      pool[p].trans[x] = np;
    if(!~p)
      pool[np].pare = 0;
    else {
      size_t q = pool[p].trans[x];
      if(pool[p].val+1 == pool[q].val)
        pool[np].pare = q;
      else {
        size_t nq = pool.size();
        pool.push_back(State(pool[p].val+1));
        memcpy(pool[nq].trans, pool[q].trans, sizeof pool[q].trans);
        pool[nq].pare = pool[q].pare;
        pool[q].pare = nq;
        pool[np].pare = nq;
        from0[nq] = p;
        from1[nq] = x;
        from2[nq] = from2[p] && x!=26;
        for(; ~p && pool[p].trans[x]==q; p = pool[p].pare)
          pool[p].trans[x] = nq;
      }
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
      printf("%3c", i2c(j));
    puts("");
    for(size_t i = 0; i<size(); i++) {
      printf("%2ld |", i);
      for(uint8_t j = 0; j<alphabet; j++)
        if(trans(i, j))
          printf("%3ld", trans(i, j));
        else
          printf("   ");
      printf(" |%3ld", val(i));
      puts("");
    }
  }
};

int n;
string s;
vector<int> len;
SuffixAutomaton<27> sam;

inline void bazinga0() {
  int _n = n;
  s = "";
  len.clear();
  sam.clear();
  len.push_back(0);
  getchar();
  while(_n) {
    char c = getchar();
    if(c=='\n') {
      s.push_back(26);
      len.back()++;
      len.push_back(0);
      sam.insert(26);
      _n--;
    } else {
      s.push_back(c-'a');
      len.back()++;
      sam.insert(c-'a');
    }
  }
  len.pop_back();
  for(vector<int>::iterator i = len.begin()+1; i<len.end(); i++)
    *i += *(i-1);
}

int val[N+1], topo[N<<1];

inline void bazinga1() {
  memset(val, 0, sizeof val);
  for(int i = 0; i<sam.size(); i++)
    val[sam.val(i)]++;
  for(int i = 1; i<=s.length(); i++)
    val[i] += val[i-1];
  for(int i = 0; i<sam.size(); i++)
    topo[--val[sam.val(i)]] = i;
}

bitset<100> c[N<<1];

inline void bazinga2() {
  for(int i = 0; i<sam.size(); i++)
    c[i].reset();
  for(int p = 0, i = 0, j = 0; i<s.length(); i++) {
    p = (int)sam.trans(p, s[i]);
    if(s[i]==26)
      j++;
    else
      c[p].set(j);
  }
  for(int *p = topo+sam.size()-1; *p; p--)
    c[sam.pare(*p)] |= c[*p];
}

inline void bazinga3() {
  vector<int> res;
  vector<string> res1;
  res.push_back(0);
  for(int i = 1; i<sam.size(); i++)
    if(from2[i] && c[i].count()>(n>>1)) {
      if(sam.val(i)>sam.val(res.front())) {
        res.clear();
        res.push_back(i);
      }
      else if(sam.val(i)==sam.val(res.front()))
        res.push_back(i);
    }
  if(sam.val(res.front())) {
    for(vector<int>::iterator i = res.begin(); i!=res.end(); i++) {
      string _;
      for(int j = *i; j; j = from0[j])
        _.push_back(from1[j]+'a');
      reverse(_.begin(), _.end());
      res1.push_back(_);
    }
    sort(res1.begin(), res1.end());
    for(vector<string>::iterator i = res1.begin(); i!=res1.end(); i++)
      cout<<*i<<endl;
  } else
    puts("?");
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  bool first = 1;
  while(scanf("%d", &n), n) {
    bazinga0();
    bazinga1();
    bazinga2();
    bazinga3();
    cout<<endl;
  }
  return 0;
}
