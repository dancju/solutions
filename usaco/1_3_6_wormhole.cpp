/*
 TASK: wormhole
 LANG: C++11
 USER: danny_c1
 */

#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const short A[] = {1, 1, 3, 3*5, 3*5*7, 3*5*7*9};
const int N = 12;

int n, res;
pair<int, int> a[N];
bool b[N], vst[N<<1], inS[N<<1];
short c[N];

bool circle(int depth, int u) {
  int v;
  vst[u] = inS[u] = 1;
  if(u&1) {
    v = c[u>>1];
    if(v==-1) {
      inS[u] = 0;
      return 0;
    }
    v <<= 1;
  } else {
    if(b[u>>1]==0) {
      inS[u] = 0;
      return 0;
    }
    v = ((u>>1)+1)<<1|1;
  }
  if(inS[v]) {
    inS[u] = 0;
    return 1;
  }
  if(vst[v]) {
    inS[u] = 0;
    return 0;
  }
  if(circle(depth+1, v)) {
    inS[u] = 0;
    return 1;
  }
  inS[u] = 0;
  return 0;
}

inline bool circle() {
  memset(vst, 0, sizeof vst);
  for(int i = 0; i < n<<1; i++)
    if(!vst[i] && circle(0, i))
      return 1;
  return 0;
}

void dfs(int depth, int x) {
  if(circle()) {
    res += A[(n>>1)-depth];
    return;
  }
  if(depth*2 == n)
    return;
  while(c[x]!=-1)
    x++;
  for(int i = x+1; i<n; i++)
    if(c[i]==-1) {
      c[i] = x;
      c[x] = i;
      dfs(depth+1, x+1);
      c[x] = c[i] = -1;
    }
}

int main() {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d%d", &a[i].second, &a[i].first);
  sort(a, a+n);
  for(int i = 1; i<n; i++)
    b[i-1] = a[i-1].first == a[i].first;
  memset(c, -1, sizeof c);
  dfs(0, 0);
  printf("%d\n", res);
  return 0;
}
