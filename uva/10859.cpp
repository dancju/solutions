#include<cstring>
#include<iostream>
#include<list>
#define FOR(i,b,e) for(__typeof(b)i=(b);i!=(e);i++)
#define FOR_EACH(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)

using namespace std;

list<short> adj[1000];
int book[1000][2];

void dp(int s, bool root) {
  FOR_EACH(t, adj[s]) {
    adj[*t].remove(s);
    dp(*t, false);
  }
  if(root) {
    book[s][1] = 1<<10;
    FOR_EACH(t, adj[s])
      book[s][1] += book[*t][1];
    int tmp = 0;
    FOR_EACH(t, adj[s])
      tmp += book[*t][0];
    book[s][1] = min(book[s][1], tmp);
  }
  else {
    book[s][1] = 1<<10;
    FOR_EACH(t, adj[s])
      book[s][1] += book[*t][1];
    int tmp = 1;
    FOR_EACH(t, adj[s])
      tmp += book[*t][0];
    book[s][1] = min(book[s][1], tmp);
    book[s][0] = (1<<10)|1;
    FOR_EACH(t, adj[s])
      book[s][0] += book[*t][1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  short nCase;
  cin >> nCase;
  while(nCase--) {
    short n, m;
    cin >> n >> m;
    FOR(i, adj+0, adj+n)
      i->clear();
    while(m--) {
      register short u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(book, 0xFF, sizeof(book));
    int count0 = 0, count1 = 0, count2 = 0;
    FOR(i, 0, n)
      if(book[i][1] == -1) {
        dp(i, true);
        count0++;
        register int &t = book[i][1];
        count1 += t>>10;
        count2 += t&0x3ff;
      }
    cout << count1 << " " << n-count0-count2 << " " << count2 << '\n';
  }
  return 0;
}
