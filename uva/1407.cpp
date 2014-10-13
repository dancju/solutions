#include<cstdio>
#include<cstring>
#include<list>

using namespace std;

/*
 * The folowing data describe a tree, whose vertices are numbers from 0 to v-1.
 * chil[i] : list of children nodes of node i
 * pare[i] : parent node of node i
 * edge[i] : the weight of the edge between node i and parent node of node i
 * size[i] : number of vertices of the subtree whose root is i
 */
list<short> chil[500];
short pare[500], edge[500], size[500];
int reco[500][500+1][2];

void dp(short u) {
  size[u] = 1;
  reco[u][1][0] = reco[u][1][1] = 0;
  for(list<short>::iterator v = chil[u].begin(); v!=chil[u].end(); v++) {
    dp(*v);
    size[u] += size[*v];
    for(short i = size[u]; i > 1; i--)
      for(short j = 1; j<i && j<=size[*v]; j++) {
        reco[u][i][0] = min(int(reco[u][i][0]),
            reco[u][i-j][0]+reco[*v][j][0]+edge[*v]*2);
        reco[u][i][1] = min(int(reco[u][i][1]),
            reco[u][i-j][1]+reco[*v][j][0]+edge[*v]*2);
        reco[u][i][1] = min(int(reco[u][i][1]),
            reco[u][i-j][0]+reco[*v][j][1]+edge[*v]);
      }
  }
}

int main() {
  short v;
  for(short iCase = 1; scanf("%hd", &v), v; iCase++) {
    short root = 0;
    for(short i = 0; i < v; i++) {
      root ^= i;
      chil[i].clear();
    }
    for(short i = 0; i < v-1; i++) {
      short u, v, d;
      scanf("%hd%hd%hd", &u, &v, &d);
      pare[u] = v;
      edge[u] = d;
      chil[v].push_back(u);
      root ^= u;
    }
    memset(reco, 0x7f, sizeof(reco));
    dp(root);
    short n;
    scanf("%hd", &n);
    printf("Case %hd:\n", iCase);
    while(n--) {
      int x;
      scanf("%d", &x);
      short ans = 0;
      for(short i = 1; i <= size[root]; i++)
        if(reco[root][i][1]<=x)
          ans = i;
      printf("%hd\n", ans);
    }
  }
  return 0;
}
