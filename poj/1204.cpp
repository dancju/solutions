#include<cassert>
#include<cstdio>
#include<cstring>
#include<queue>

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
  inline const vector<short>& output(int x) const {
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

inline int min(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }

int r, c, n, i, j;
char A[1000][1001], B[1001];
struct Res { short x, y; char z; } res[1000];
AC<26> ac;

void fA(size_t x, short y) { res[y].x = r-x-1; res[y].y = i; res[y].z = 'A'; }
void fB(size_t x, short y) {
  res[y].x = min(i, r-1)-x;
  res[y].y = max(0, i-r+1)+x;
  res[y].z = 'B';
}
void fC(size_t x, short y) { res[y].x = i; res[y].y = x; res[y].z = 'C'; }
void fD(size_t x, short y) {
  res[y].x = max(i-c+1, 0)+x;
  res[y].y = max(0, c-i-1)+x;
  res[y].z = 'D';
}
void fE(size_t x, short y) { res[y].x = x; res[y].y = i; res[y].z = 'E'; }
void fF(size_t x, short y) {
  res[y].x = max(0, i-c+1)+x;
  res[y].y = min(i, c-1)-x;
  res[y].z = 'F';
}
void fG(size_t x, short y) { res[y].x = i; res[y].y = c-x-1; res[y].z = 'G'; }
void fH(size_t x, short y) {
  res[y].x = min(i, r-1)-x;
  res[y].y = min(c-1, c+r-2-i)-x;
  res[y].z = 'H';
}

int main(){
  scanf("%d%d%d", &r, &c, &n);
  for(int i = 0; i < r; i++) {
    scanf("%s", A[i]);
    for(char *j = A[i]; *j; j++)
      *j -= 'A';
  }
  ac.clear();
  for(int i = 0; i < n; i++) {
    scanf("%s", B);
    size_t _ = strlen(B);
    for(char *j = B; j!=B+_; j++)
      *j -= 'A';
    ac.insertPattern(B, B+_);
  }
  ac.construct();
  for(i = 0; i < c; i++) {
    for(j = 0; j < r; j++)
      B[j] = A[r-1-j][i];
    ac.match(B, B+r, fA);
  }
  for(i = 0; i < r+c-1; i++) {
    for(j = 0; j<min(i+1, r, c, r+c-i-1); j++)
      B[j] = A[min(i, r-1)-j][max(0, i-r+1)+j];
    ac.match(B, B+min(i+1, r, c, r+c-i-1), fB);
  }
  for(i = 0; i < r; i++) {
    for(j = 0; j < c; j++)
      B[j] = A[i][j];
    ac.match(B, B+c, fC);
  }
  for(i = 0; i < r+c-1; i++) {
    for(j = 0; j<min(i+1, r, c, r+c-i-1); j++)
      B[j] = A[max(i-c+1, 0)+j][max(c-1-i, 0)+j];
    ac.match(B, B+min(i+1, r, c, r+c-i-1), fD);
  }
  for(i = 0; i < c; i++) {
    for(j = 0; j < r; j++)
      B[j] = A[j][i];
    ac.match(B, B+r, fE);
  }
  for(i = 0; i < r+c-1; i++) {
    for(j = 0; j < min(r, c, i+1, r+c-1-i); j++)
      B[j] = A[max(0, i-c+1)+j][min(i, c-1)-j];
    ac.match(B, B+min(i+1, r, c, r+c-i-1), fF);
  }
  for(i = 0; i < r; i++) {
    for(j = 0; j < c; j++)
      B[j] = A[i][c-1-j];
    ac.match(B, B+c, fG);
  }
  for(i = 0; i < r+c-1; i++) {
    for(j = 0; j<min(i+1, r, c, r+c-i-1); j++)
      B[j] = A[min(i, r-1)-j][min(c-1, c+r-2-i)-j];
    ac.match(B, B+min(i+1, r, c, r+c-i-1), fH);
  }
  for(int i = 0; i < n; i++)
    printf("%hd %hd %c\n", res[i].x, res[i].y, res[i].z);
  return 0;
}
