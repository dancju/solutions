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

short i, f[1000][1000];
char t1[1001];
char text[1000][1001];
AC<26> ac;

void action(size_t x, short y) { if(i-y>=0) f[i-y][x]++; }

int main() {
  short kase;
  scanf("%hd", &kase);
  while(kase--) {
    short r, c, t0;
    int res = 0;
    ac.clear();
    scanf("%hd%hd", &r, &c);
    for(short i = 0; i<r; i++) {
      scanf("%s", text[i]);
      for(char *j = text[i]; j!=text[i]+c; j++)
        *j -= 'a';
    }
    scanf("%hd%*hd", &t0);
    for(short i = 0; i<t0; i++) {
      scanf("%s", t1);
      short t2 = strlen(t1);
      for(char *i = t1; i != t1+t2; i++)
        *i -= 'a';
      ac.insertPattern(t1, t1+t2);
    }
    ac.construct();
    memset(f, 0, sizeof(f));
    for(i = 0; i<r; i++)
      ac.match(text[i], text[i]+c, action);
    for(i = 0; i<r; i++)
      for(short j = 0; j<c; j++)
        if(f[i][j]==t0)
          res++;
    printf("%d\n", res);
  }
  return 0;
}
