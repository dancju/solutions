/*
PROG: agrinet
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

short n;
struct edge{
  short s, t;
  int w;
  bool operator < (const edge &other)const{ return w>other.w; }
};
priority_queue<edge> g;
void init(){
  cin >> n;
  edge tmp;
  for(tmp.s = 0; tmp.s<n; tmp.s++)
    for(tmp.t = 0; tmp.t<n; tmp.t++){
      cin >> tmp.w;
      if(tmp.s<tmp.t)
        g.push(tmp);
    }
}

class disjoint_set{
  vector<short> p;
  public:
  void assign(short n){
    p.assign(n, 0);
    for(short i = 0; i<n; i++)
      p[i] = i;
  }
  short parent(short v){ return p[v]==v ? v : p[v] = parent(p[v]); }
  void merge(short v0, short v1){ p[parent(v1)] = parent(v0); }
  bool same(short v0, short v1){ return parent(v0)==parent(v1); }
} v;


int main(){
  freopen("agrinet.in", "r", stdin);
  init();
  v.assign(n);
  v.merge(g.top().s, g.top().t);
  int ans = g.top().w;
  g.pop();
  while(!g.empty()){
    if(!v.same(g.top().s, g.top().t)){
      v.merge(g.top().s, g.top().t);
      ans += g.top().w;
    }
    g.pop();
  }
  freopen("agrinet.out", "w", stdout);
  cout << ans << endl;
  return 0;
}
