#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

using namespace std;

struct Edge {
  bool dead;
  short u, v;
};

vector<short> a[50];
Edge b[1000];
short n;
vector<short> res;

void dfs(int s) {
  while(!a[s].empty()) {
    short e = a[s].back();
    a[s].pop_back();
    if(b[e].dead)
      dfs(s);
    else {
      b[e].dead = 1;
      short t = s^b[e].u^b[e].v;
      dfs(t);
      res.push_back(t);
    }
  }
}

int main() {
  short nCase;
  scanf("%hd", &nCase);
  for(short iCase = 1; iCase <= nCase; iCase++) {
    short s;
    scanf("%hd", &n);
    for(int i = 0; i < 50; i++)
      a[i].clear();
    memset(b, 0, sizeof(b));
    res.clear();
    for(int i = 0; i < n; i++) {
      short u, v;
      scanf("%hd%hd", &u, &v);
      u--;
      v--;
      b[i].u = u;
      b[i].v = v;
      a[u].push_back(i);
      a[v].push_back(i);
      s = u;
    }
    dfs(s);
    printf("Case #%hd\n", iCase);
    if(s!=res.front())
      puts("some beads may be lost");
    else {
      printf("%d %d\n", s+1, res.back()+1);
      for(int i = res.size()-1; i > 0; i--)
        printf("%d %d\n", res[i]+1, res[i-1]+1);
    }
    if(iCase != nCase)
      puts("");
  }
  return 0;
}
