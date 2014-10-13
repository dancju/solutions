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

template<uint8_t sigma> class AC {
  struct State {
    short depth;
    size_t fail, go[sigma];
    vector<short> output;
  };
  short iOutput;
  vector<State> state;
public:
  AC() { state.push_back(State()); }
  inline void clear() {
    iOutput = 0;
    state.clear();
    state.push_back(State());
  }
  template<class I> inline void insertPattern(I lo, I hi) {
    assert(lo<hi);
    size_t p = 0;
    for(I i = lo; i!=hi; i++) {
      assert(0<=*i && *i<sigma);
      if(!state[p].go[*i]) {
        state[p].go[*i] = state.size();
        state.push_back(State());
        state.back().depth = state[p].depth+1;
      }
      p = state[p].go[*i];
    }
    assert(iOutput>=0);
    state[p].output.push_back(iOutput++);
  }
  inline void construct() {
    queue<size_t> q;
    for(uint8_t i = 0; i<sigma; i++)
      if(state[0].go[i])
        q.push(state[0].go[i]);
    while(q.size()) {
      size_t u = q.front();
      q.pop();
      for(uint8_t i = 0; i<sigma; i++) {
        size_t &v = state[u].go[i];
        if(v) {
          size_t j = state[u].fail;
          while(j && !state[j].go[i])
            j = state[j].fail;
          size_t k = state[j].go[i];
          state[v].fail = k;
          state[v].output.insert(state[v].output.end(), state[k].output.begin(), state[k].output.end());
          q.push(v);
        } else
          v = state[state[u].fail].go[i];
      }
    }
  }
  inline size_t size() const { return state.size(); }
  inline size_t go(size_t x, uint8_t y) const {
    assert(0<=x && x<state.size() && 0<=y && y<sigma);
    return state[x].go[y];
  }
  inline const vector<short>& output(size_t x) const {
    assert(0<=x && x<size());
    return state[x].output;
  }
  template<class I> inline void match(I lo, I hi, void action(size_t, short)) {
    assert(lo<hi);
    size_t p = 0;
    for(I i = lo; i!=hi; i++) {
      assert(0<=*i && *i<sigma);
      p = go(p, *i);
      for(vector<short>::iterator j = state[p].output.begin();
          j!=state[p].output.end();
          j++)
        action(i-lo-state[p].depth+1, *j);
    }
  }
};

inline char c2i(char c) {
  switch(c) {
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    default:
      assert(c=='T');
      return 3;
  }
};

inline char i2c(char i) {
  switch(i) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    default:
      assert(i==3);
      return 'T';
  }
}

short n;
unsigned A[1001][921];
char B[1001];
AC<4> ac;

int main() {
  for(short kase = 1; scanf("%hd", &n), n; kase++) {
    ac.clear();
    while(n--) {
      scanf("%*c%s", B);
      size_t _ = strlen(B);
      for(char *i = B; i!=B+_; i++)
        *i = c2i(*i);
      ac.insertPattern(B, B+_);
    }
    ac.construct();
    scanf("%*c%s", B);
    size_t _ = strlen(B);
    memset(A, -1, sizeof(A));
    A[0][0] = 0;
    for(int i = 0; i<_; i++)
      for(int j = 0; j < ac.size(); j++)
        if(A[i][j]!=UINT_MAX)
          for(short k = 0; k < 4; k++)
            if(!ac.output(ac.go(j, k)).size())
              A[i+1][ac.go(j, k)]
              = min(A[i+1][ac.go(j, k)], A[i][j]+(c2i(B[i])!=k));
    unsigned res = UINT_MAX;
    for(int j = 0; j<ac.size(); j++)
      res = min(res, A[_][j]);
    printf("Case %hd: %d\n", kase, res);
  }
  return 0;
}
