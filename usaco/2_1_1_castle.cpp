/*
PROG: castle
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
using namespace std;

short m, n, A[50][50];

class disjoint_set{
  short _parent[2500], _rank[2500];
  public:
  short size;
  void assign(short n){
    for(short i = 0; i<n; i++){
      _parent[i] = i;
      _rank[i] = 1;
    }
    size = n;
  }
  short parent(short x){ return x==_parent[x] ? x : _parent[x] = parent(_parent[x]); }
  void merge(short x, short y){
    if(parent(x)==parent(y)) return;
    if(_rank[x]>_rank[y]){
      _rank[_parent[x]] += _rank[_parent[y]]; _rank[_parent[y]] = 0;
      _parent[_parent[y]] = _parent[x];
    }
    else{
      _rank[_parent[y]] += _rank[_parent[x]]; _rank[_parent[x]] = 0;
      _parent[_parent[x]] = _parent[y];
    }
    size--;
  }
  short rank(short x){ return _rank[parent(x)]; }
  bool same(short x, short y){ return parent(x)==parent(y); }
} B;

int main(){
  freopen("castle.in", "r", stdin);
  cin >> n >> m;
  B.assign(m*n);
  for(short i = 0; i<m; i++)
    for(short j = 0; j<n; j++){
      cin >> A[i][j];
      if((A[i][j]&1)==0) B.merge(i*n+j, i*n+j-1);
      if((A[i][j]&2)==0) B.merge(i*n+j, (i-1)*n+j);
    }
  freopen("castle.out", "w", stdout);
  cout << B.size << endl;
  short tmp = 0;
  for(short i = 0; i<m*n; i++) tmp = max(tmp, B.rank(i));
  cout << tmp << endl;
  tmp = 0;
  short ans0, ans1;
  char ans2;
  for(short j = 0; j<n; j++){
    for(short i = m-1; i; i--)
      if((A[i][j]&2) && !B.same(i*n+j, i*n+j-n) && tmp<B.rank(i*n+j)+B.rank(i*n+j-n)){
        tmp = B.rank(i*n+j)+B.rank(i*n+j-n);
        ans0 = i; ans1 = j; ans2 = 'N';
      }
    if(j!=n-1) for(short i = m-1; i>=0; i--)
      if((A[i][j]&4) && !B.same(i*n+j, i*n+j+1) && tmp<B.rank(i*n+j)+B.rank(i*n+j+1)){
        tmp = B.rank(i*n+j)+B.rank(i*n+j+1);
        ans0 = i; ans1 = j; ans2 = 'E';
      }
  }
  cout << tmp << endl << ans0+1 << ' ' << ans1+1 << ' ' << ans2 << endl;
  return 0;
}
