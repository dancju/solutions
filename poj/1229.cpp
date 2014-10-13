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

char d0[256];
string d10, d11;
vector<string> d20, d21;
vector<vector<bool> > d3;
queue<pair<short, short> > d31;
bool res;

inline void bazinga0(string &d1, vector<string> &d2) {
  d1.push_back('.');
  d2.clear();
  while(d1.length()) {
    size_t t0 = d1.find('.');
    string t1 = d1.substr(0, t0);
    d1 = d1.substr(t0+1);
    if(t1=="?") {
      d2.push_back("!");
      d2.push_back("?");
      d2.push_back("?");
    } else if(t1=="!") {
      d2.push_back("!");
      d2.push_back("!");
      d2.push_back("*");
    } else
      d2.push_back(t1);
  }
}

inline void bazinga1(short i, short j) {
  if(d3[i][j])
    return;
  d3[i][j] = 1;
  d31.push(make_pair(i, j));
}

inline bool allQ(vector<string>::iterator lo, vector<string>::iterator hi) {
  for(vector<string>::iterator i = lo; i!=hi; i++)
    if(*i!="?")
      return 0;
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/dan/git/Main/input.txt", "r", stdin);
#endif
  short kase;
  scanf("%hd", &kase);
  while(kase--) {
    //==========================================================================
    scanf("%s", d0);
    d10.assign(d0);
    scanf("%s", d0);
    d11.assign(d0);
    //==========================================================================
    bazinga0(d10, d20);
    bazinga0(d11, d21);
    d3.assign(d20.size()+1, vector<bool>(d21.size()+1, 0));
    if(d20.size()>=SHRT_MAX || d21.size()>=SHRT_MAX)
      while(1);
    d3[0][0] = 1;
    while(d31.size())
      d31.pop();
    d31.push(make_pair(0, 0));
    res = 0;
    while(d31.size()) {
      pair<short, short> u = d31.front();
      d31.pop();
      if(u.first==d20.size() && u.second==d21.size()) {
        res = 1;
        break;
      }
      if(u.first==d20.size()) {
        if(allQ(d21.begin()+u.second, d21.end())) {
          res = 1;
          break;
        } else
          continue;
      }
      if(u.second==d21.size()) {
        if(allQ(d20.begin()+u.first, d20.end())) {
          res = 1;
          break;
        } else
          continue;
      }
      if(d20[u.first]=="*") {
        if(d21[u.second]=="*")
          for(short i = u.first+1; i<=d20.size(); i++)
            bazinga1(i, u.second+1);
        for(short i = u.second+1; i<=d21.size(); i++)
          bazinga1(u.first+1, i);
      } else if(d20[u.first]=="?") {
        if(d21[u.second]=="*")
          for(int i = u.first+2; i<=d20.size(); i++)
            bazinga1(i, u.second+1);
        else if(d21[u.second]=="?")
          bazinga1(u.first, u.second+1);
        bazinga1(u.first+1, u.second+1);
        bazinga1(u.first+1, u.second);
      } else if(d20[u.first]=="!") {
        if(d21[u.second]=="*")
          for(short i = u.first+2; i<=d20.size(); i++)
            bazinga1(i, u.second+1);
        if(d21[u.second]=="?")
          bazinga1(u.first, u.second+1);
        bazinga1(u.first+1, u.second+1);
      } else {
        if(d21[u.second]=="*") {
          for(short i = u.first+1; i<=d20.size(); i++)
            bazinga1(i, u.second+1);
        } if(d21[u.second]=="?") {
          bazinga1(u.first, u.second+1);
          bazinga1(u.first+1, u.second+1);
        } else if(d21[u.second]=="!")
          bazinga1(u.first+1, u.second+1);
        else if(d20[u.first]==d21[u.second])
          bazinga1(u.first+1, u.second+1);
      }
    }
    //==========================================================================
    puts(res ? "YES" : "NO");
  }
  return 0;
}
