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

inline uint8_t c2i(char x) {
  if(x>='0' && x<='9')
    return x-'0';
  if(x>='A' && x<='Z')
    return x-'A'+10;
  assert(x>='a' && x<='z');
  return x-'a'+36;
}

double prob[62], f[110][410];
AC<62> ac;

int main() {
  short nCase;
  scanf("%hd", &nCase);
  for(short iCase = 1; iCase<=nCase; iCase++) {
    short t0;
    ac.clear();
    scanf("%hd", &t0);
    while(t0--) {
      char _[21];
      scanf("%*c%s", _);
      size_t __ = strlen(_);
      for(char *i = _; i!=_+__; i++)
        *i = c2i(*i);
      ac.insertPattern(_, _+__);
    }
    ac.construct();
    scanf("%hd", &t0);
    memset(prob, 0, sizeof(prob));
    while(t0--) {
      char t1;
      scanf("%*c%c", &t1);
      scanf("%lf", prob+c2i(t1));
    }
    scanf("%hd", &t0);
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(int i = 0; i<t0; i++)
      for(short j = 0; j<ac.size(); j++)
        if(f[i][j])
          for(short k = 0; k < 62; k++)
            if(prob[k] && !ac.output(ac.go(j, k)).size())
              f[i+1][ac.go(j, k)] += f[i][j]*prob[k];
    double res = 0;
    for(short j = 0; j<ac.size(); j++)
      res += f[t0][j];
    printf("Case #%hd: %lf\n", iCase, res);
  }
  return 0;
}
