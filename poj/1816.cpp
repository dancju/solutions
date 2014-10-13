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

inline char c2i(char c) {
  switch(c) {
    case '*':
      return 27;
    case '?':
      return 26;
    default:
      return c-'a';
  }
}

template<char sigma> struct Trie {
  struct Node {
    size_t go[sigma];
    vector<int> output;
    Node() { memset(go, 0, sizeof go); }
  };
  int iOutput;
  vector<Node> pool;
  Trie() : iOutput(0) { pool.push_back(Node()); }
  template<class I> inline void insert(I lo, I hi) {
    size_t p = 0;
    for(I i = lo; i!=hi; i++) {
      if(!pool[p].go[*i]) {
        pool[p].go[*i] = pool.size();
        pool.push_back(Node());
      }
      p = pool[p].go[*i];
    }
    pool[p].output.push_back(iOutput++);
  }
  inline const Node& operator[](size_t x) { return pool[x]; }
};

Trie<28> trie;
bool b[1+28+28*28+28*28*28+100000+100000+100000+1][20+1];
vector<int> res;

void dfs(size_t p, char* lo, char* hi) {
  if(b[p][hi-lo])
    return;
  b[p][hi-lo] = 1;
  if(hi==lo) {
    res.insert(res.end(), trie[p].output.begin(), trie[p].output.end());
    if(trie[p].go[27])
      dfs(trie[p].go[27], lo, hi);
    return;
  }
  if(trie[p].go[27])
    for(char *i = lo; i<=hi; i++)
      dfs(trie[p].go[27], i, hi);
  if(trie[p].go[*lo])
    dfs(trie[p].go[*lo], lo+1, hi);
  if(trie[p].go[26])
    dfs(trie[p].go[26], lo+1, hi);
}

char _s[21];

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  int nP, nT;
  scanf("%d%d", &nP, &nT);
  while(nP--) {
    scanf("%s", _s);
    char *j = _s+1;
    for(char *i = _s+1; *i; i++)
      if(*(j-1) != '*' || *i != '*') {
        *j = *i;
        j++;
      }
    for(char *i = _s; i<j; i++)
      *i = c2i(*i);
    trie.insert(_s, j);
  }
  while(nT--) {
    scanf("%s", _s);
    char *hi = _s+strlen(_s);
    for(char *i = _s; *i; i++)
      *i = c2i(*i);
    memset(b, 0, sizeof b);
    res.clear();
    dfs(0, _s, hi);
    sort(res.begin(), res.end());
    if(res.size()) {
      printf("%d", res.front());
      for(vector<int>::iterator i = res.begin()+1; i<res.end(); i++)
        printf(" %d", *i);
      puts("");
    } else
      puts("Not match");
  }
  return 0;
}
