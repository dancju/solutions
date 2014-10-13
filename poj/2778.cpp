#include<cassert>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

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

const int MOD = 100000;
char size;

struct Matrix {
  unsigned val[95][95];
  inline unsigned* operator[](char x) { return val[x]; }
};

Matrix operator*(Matrix &a, Matrix &b) {
  Matrix res{};
  for(char i = 0; i<size; i++)
    for(char j = 0; j<size; j++)
      for(char k = 0; k<size; k++) {
        res[i][j] += (long long)a[i][k]*b[k][j]%MOD;
        res[i][j] %= MOD;
      }
  return res;
}

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
}

AC<4> ac;
Matrix a, res0;
unsigned res1;

int main() {
  int n;
  short _;
  scanf("%hd%d", &_, &n);
  while(_--) {
    char __[11];
    scanf("%s", __);
    char ___ = strlen(__);
    for(char *i = __; i!=__+___; i++)
      *i = c2i(*i);
    ac.insertPattern(__, __+___);
  }
  ac.construct();
  size = ac.size();
  for(char j = 0; j<ac.size(); j++)
    for(char k = 0; k<4; k++)
      a[ac.go(j, k)][j] += ac.output(ac.go(j, k)).size()==0;
  for(char i = 0; i<ac.size(); i++)
    res0[i][i] = 1;
  for(; n; a = a*a, n>>=1)
    if(n&1)
      res0 = res0*a;
  for(char i = 0; i<ac.size(); i++) {
    res1 += res0[i][0];
    res1 %= MOD;
  }
  printf("%d\n", res1);
  return 0;
}
