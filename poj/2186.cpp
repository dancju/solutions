#include<cassert>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

class Digraph {
  vector<int> *adj;
public:
  int v;
  Digraph(int v): v(v) {
    assert(v);
    adj = new vector<int>[v];
  }
  ~Digraph() { delete[] adj; }
  inline vector<int>& operator[](int x) {
    assert(x>=0 && x<v);
    return adj[x];
  }
  inline void addEdge(int a, int b) {
    assert(a>=0 && a<v && b>=0 && b<v);
    adj[a].push_back(b);
  }
};

class SCC {
  int stamp, *dfn, *low, *belong;
  bool *inS;
  stack<int> s;
  Digraph &g;
  void tarjan(int a) {
    dfn[a] = low[a] = ++stamp;
    s.push(a);
    inS[a] = 1;
    for(vector<int>::iterator i = g[a].begin(); i != g[a].end(); i++) {
      int& b = *i;
      if(!dfn[b]) { // 樹枝邊
        tarjan(b);
        low[a] = min(low[a], low[b]);
      } else if(inS[b]) // 返祖邊
        low[a] = min(low[a], dfn[b]);
    }
    if(low[a] == dfn[a]) {
      for(int b = s.top(); b != a; inS[b] = 0, s.pop(), b = s.top())
        belong[b] = count;
      inS[a] = 0;
      s.pop();
      belong[a] = count;
      count++;
    }
  }
public:
  int count;
  SCC(Digraph &g) : g(g) {
    int& v = g.v;
    count = stamp = count = 0;
    inS = new bool[v];
    memset(inS, 0, v*sizeof(bool));
    low = new int[v];
    dfn = new int[v];
    belong = new int[v];
    memset(dfn, 0, v*sizeof(int));
    for(int i = 0; i < v; i++)
      if(!dfn[i])
        tarjan(i);
    delete[] low;
    delete[] dfn;
    delete[] inS;
  }
  ~SCC() { delete[] belong; }
  inline int operator[](int x) { return belong[x]; }
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Digraph g(n);
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    g.addEdge(a-1, b-1);
  }
  SCC scc(g);
  int *outD = new int[scc.count];
  memset(outD, 0, scc.count*sizeof(int));
  for(int s = 0; s < n; s++)
    for(vector<int>::iterator i = g[s].begin(); i != g[s].end(); i++)
      if(scc[s] != scc[*i])
        outD[scc[s]]++;
  int t0 = -1;
  for(int i = 0; i < scc.count; i++)
    if(!outD[i]) {
      if(t0 == -1)
        t0 = i;
      else {
        t0 = -1;
        break;
      }
    }
  delete[] outD;
  if(t0 == -1)
    puts("0");
  else {
    int t1 = 0;
    for(int i = 0; i < n; i++)
      if(scc[i] == t0)
        t1++;
    printf("%d\n", t1);
  }
  return 0;
}
