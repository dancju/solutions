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

template <uint8_t SIGMA, size_t CAPACITY> struct Trie {
  size_t size, pool[CAPACITY][SIGMA];
  Trie() : size(1) {}
  template<class I> inline void insertPattern(I lo, I hi) {
    size_t p = 0;
    for(I i = lo; i!=hi; i++) {
      if(!pool[p][*i]) {
        pool[p][*i] = size;
        size++;
      }
      p = pool[p][*i];
    }
  }
  size_t* operator[](size_t x) { return pool[x]; }
};

Trie<26, 100001> trie;

char bazinga(long u) {
  char res = 0;
  bool mark = 0;
  for(int i = 0; i<26; i++) {
    int v = trie[u][i];
    if(!v)
      continue;
    mark = 1;
    res |= bazinga(v)^3;
    if(res==3)
      return 3;
  }
  return mark?res:1;
}

int main() {
  int n, k;
  cin>>n>>k;
  while(n--) {
    string _;
    cin>>_;
    for(char &c : _)
      c -= 'a';
    trie.insertPattern(_.begin(), _.end());
  }
  char x = bazinga(0);
  puts(x==3||(k&1)&&(x==2) ? "First" : "Second");
  return 0;
}
