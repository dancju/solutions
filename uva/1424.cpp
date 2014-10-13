#include<cstring>
#include<iostream>
#include<list>

using namespace std;

list<short> adj[100];
short path[200], f[200][100];

int main() {
  ios::sync_with_stdio(false);
  short nCase;
  cin >> nCase;
  while(nCase--) {
    short v, e;
    cin >> v >> e;
    for(int i = 0; i < v; i++) {
      adj[i].clear();
      adj[i].push_back(i);
    }
    while(e--) {
      short u, v;
      cin >> u >> v;
      adj[u-1].push_back(v-1);
      adj[v-1].push_back(u-1);
    }
    short n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> path[i];
      path[i] -= 1;
    }
    memset(f, 0x7f, sizeof(f));
    for(int j = 0; j < v; j++)
      f[0][j] = 1;
    f[0][path[0]] = 0;
    for(int i = 1; i < n; i++)
      for(int j = 0; j < v; j++)
        for(list<short>::iterator k = adj[j].begin(); k!=adj[j].end(); k++)
          f[i][j] = min((int)f[i][j], f[i-1][*k]+(j!=path[i]));
    short ans = 0xfff;
    for(int j = 0; j < v; j++)
      ans = min(ans, f[n-1][j]);
    cout << ans << endl;
  }
  return 0;
}
