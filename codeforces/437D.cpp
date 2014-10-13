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
#define DOWN(i,hi,lo) for(__typeof(hi)i=(hi);i!=lo;i--)
#define EACH(i,c)     for(__typeof(c.begin())i=(c).begin();i!=(c).end();i++)
#define UPTO(i,lo,hi) for(__typeof(lo)i=(lo);i!=(hi);i++)
#define endl '\n'

const long double PI = acos(-1.L);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

class DisjointSets {
  int n, *parent, *rank;
public:
  DisjointSets(int n) {
    assert(n > 0);
    this->n = n;
    parent = new int[n];
    rank = new int[n];
    for(int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  ~DisjointSets() {
    delete[] parent;
    delete[] rank;
  }
  inline bool connected(int a, int b) {
    assert(a>=0 && a<n && b>=0 && b<n);
    return find(a)==find(b);
  }
  int find(int i) const {
    assert(i>=0 && i<n);
    return parent[i]==i ? i : (parent[i]=find(parent[i]));
  }
  inline int size(int i) const {
    assert(i>=0 && i<n);
    return rank[find(i)];
  }
  inline void merge(int a, int b) {
    assert(a>=0 && a<n && b>=0 && b<n);
    a = find(a);
    b = find(b);
    if(a == b)
      return;
    if(rank[a] < rank[b]) {
      int t = a;
      a = b;
      b = t;
    }
    rank[a] += rank[b];
    rank[b] = 0;
    parent[b] = a;
  }
};


pair<int, int> a[100000];
vector<int> adj[100000];
bool b[100000];

inline bool orderBySecond(pair<int, int> a, pair<int, int> b) {
  return a.second>b.second;
}

int v, e;

int main() {
  scanf("%d%d", &v, &e);
  UPTO(i, 0, v) {
    scanf("%d", &a[i].second);
    a[i].first = i;
  }
  sort(a, a+v, orderBySecond);
  while(e--) {
    int v0, v1;
    scanf("%d%d", &v0, &v1);
    v0--;
    v1--;
    adj[v0].push_back(v1);
    adj[v1].push_back(v0);
  }
  DisjointSets ds(v);
  ll res = 0;
  UPTO(i, a+0, a+v) {
    int u = i->first;
    b[u] = 1;
    set<int> t;
    EACH(j, adj[u]) {
      int v = *j;
      if(b[v])
        t.insert(ds.find(v));
    }
    ll t0 = 0, t1 = 0;
    EACH(j, t) {
      ll _ = ds.size(*j);
      t0 += _;
      t1 += _*_;
      ds.merge(u, *j);
    }
    res += (t0+(t0*t0-t1)/2)*i->second;
  }
  printf("%lf\n", res*2.0/v/(v-1));
  return 0;
}