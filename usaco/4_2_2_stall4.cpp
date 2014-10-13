#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

int n, m, a[201][201];
void init(){
  cin >> n >> m;
  for(int i = 1; i<=n; i++){
    cin >> a[i][0];
    for(int j = 1; j<=a[i][0]; j++)
      cin >> a[i][j];
  }
}

bool book[201];
int lk[201];
bool match(int x){
  for(int i = 1; i<=a[x][0]; i++)
    if(!book[a[x][i]]){
      book[a[x][i]] = true;
      if(lk[a[x][i]]==0||match(lk[a[x][i]])){
	lk[a[x][i]] = x;
	return true;
      }
    }
  return false;
}

int main(){
  freopen("stall4.in", "r", stdin);
  freopen("stall4.out", "w", stdout);
  init();
  int ans = 0;
  for(int i = 1; i<=n; i++){
    memset(book, 0, sizeof(book));
    ans += match(i);
  }
  cout << ans << endl;
  return 0;
}
