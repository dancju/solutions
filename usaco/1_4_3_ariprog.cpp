/*
ID: danny_c1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

bitset<125001> s;
vector<int> l;

struct cor{ int a, d; };
vector<cor> sol;
bool cmp(cor a, cor b){ return (a.d<b.d)||((a.d==b.d)&&(a.a<b.a)); }

bool check(int a, int d, int n){
  if(n==0) return true;
  if(!s[a]) return false;
  return check(a+d, d, n-1);
}

int main(){
  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i<=m; i++)
    for(int j = i; j<=m; j++){
      l.push_back(i*i+j*j);
      s[l.back()] = 1;
    }
  cor tmp;
  for(vector<int>::iterator i = l.begin(); i<l.end(); i++)
    for(int d = 1; d<=(m*m+m*m-(*i))/(n-1); d++)
      if(check(*i, d, n)){
        tmp.a = *i; tmp.d = d;
        sol.push_back(tmp);
      }
  if(sol.empty())
    cout << "NONE" << endl;
  else{
    sort(sol.begin(), sol.end(), cmp);
    for(vector<cor>::iterator i = sol.begin(); i<sol.end(); i++) cout << (*i).a << ' ' << (*i).d << endl;
  }
  return 0;
}
