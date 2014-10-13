#define FOR_EACH(i,c) for(auto (i) = (c).begin(); (i) != (c).end(); (i)++)
#include<algorithm>
#include<array>
#include<bitset>
#include<complex>
#include<deque>
#include<forward_list>
#include<functional>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>

const long double PI = 2*acos(.0L);
typedef long long LLONG;
typedef unsigned long long ULLONG;
using namespace std;

char b[11][11];
vector<short> a[11];
short ind[11], outd[11];
bool vistd[11];
vector<short> topo;
short res[11];

void dfs(short u) {
  vistd[u] = 1;
  FOR_EACH(v, a[u])
    if(!vistd[*v])
      dfs(*v);
  topo.push_back(u);
}

int main() {
  short nCase;
  scanf("%hd", &nCase);
  while(nCase--) {
    //============================= INPUT ==============================
    short n;
    scanf("%hd%*c", &n);
    for(short i = 0; i <= n; i++)
      a[i].clear();
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
    for(short i = 0; i < n; i++)
      for(short j = i+1; j <= n; j++) {
        scanf("%c", &b[i][j]);
        if(b[i][j] == '+') {
          a[i].push_back(j);
          outd[i]++;
          ind[j]++;
        } else if(b[i][j] == '-') {
          a[j].push_back(i);
          outd[j]++;
          ind[i]++;
        }
      }
    //============================= TOPOLOGICAL SORT ====================
    topo.clear();
    memset(vistd, 0, sizeof(vistd));
    for(short i = 0; i <= n; i++)
      if(!vistd[i])
        dfs(i);
    res[topo[n]] = 0;
    for(short i = n-1, timestamp = 0; i >= 0; i--) {
      if(b[min(topo[i], topo[i+1])][max(topo[i], topo[i+1])]=='0')
        res[topo[i]] = timestamp;
      else
        res[topo[i]] = ++timestamp;
    }
    for(short i = 1; i <= n; i++) {
      if(i != 1)
        putchar(' ');
      printf("%d", res[i]-res[i-1]);
    }
    puts("");
  }
  return 0;
}
