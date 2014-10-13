#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

short m, n;
vector<short> a;
void init(){
  short t0, t1, t2;
  cin >> n >> m >> t0;
  a.assign(n+1, 0);
  while(t0--){
    cin >> t1 >> t2;
    a[t1-1] |= 1<<t2-1;
  }
  a[n] = (1<<m)-1;
}

vector< vector<short> > f0, f1;
short b0, b1, b2;
void put(short y, short f){
  short j = y;
  while((++j)<=m-2)
    if(((b0&(1<<j-1))==0)
        &&((b0&(1<<j))==0)
        &&((b0&(1<<j+1))==0)
        &&((b1&(1<<j-1))==0)
        &&((b1&(1<<j))==0)
        &&((b1&(1<<j+1))==0))
      break;
  if(j<=m-2){
    b0 ^= 1<<j-1; b0 ^= 1<<j; b0 ^= 1<<j+1;
    b1 ^= 1<<j-1; b1 ^= 1<<j; b1 ^= 1<<j+1;
    f1[b1][b2] = max(f1[b1][b2], ++f);
    put(j, f--);
    b0 ^= 1<<j-1; b0 ^= 1<<j; b0 ^= 1<<j+1;
    b1 ^= 1<<j-1; b1 ^= 1<<j; b1 ^= 1<<j+1;
  }
  j = y;
  while((++j)<=m-1)
    if(((b0&(1<<j-1))==0)
        &&((b0&(1<<j))==0)
        &&((b1&(1<<j-1))==0)
        &&((b1&(1<<j))==0)
        &&((b2&(1<<j-1))==0)
        &&((b2&(1<<j))==0))
      break;
  if(j<=m-1){
    b0 ^= 1<<j-1; b0 ^= 1<<j;
    b1 ^= 1<<j-1; b1 ^= 1<<j;
    b2 ^= 1<<j-1; b2 ^= 1<<j;
    f1[b1][b2] = max(f1[b1][b2], ++f);
    put(j, f--);
    b0 ^= 1<<j-1; b0 ^= 1<<j;
    b1 ^= 1<<j-1; b1 ^= 1<<j;
    b2 ^= 1<<j-1; b2 ^= 1<<j;
  }
  if(y<=m-2)
    put(y+1, f);
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  short cases, ans;
  cin >> cases;
  while(cases--){
    init();
    //for(short i = 0; i<=n; i++) b(a[i]);
    f1.assign(1<<m, vector<short>(1<<m, 0));
    for(short k = 0; k<n-1; k++){
      f0.assign(f1.begin(), f1.end());
      f1.assign(1<<m, vector<short>(1<<m, 0));
      for(b0 = 0; b0<(1<<m); b0++)
        if((b0&a[k])==a[k])
          for(b1 = 0; b1<(1<<m); b1++)
            if((b0==a[k]&&b1==a[k+1])||f0[b0][b1]){
              b2 = a[k+2];
              f1[b1][b2] = max(f1[b1][b2], f0[b0][b1]);
              put(0, f0[b0][b1]);
            }
    }
    ans = 0;
    for(int i = 0; i<(1<<m); i++)
      for(int j = 0; j<(1<<m); j++)
        ans = max(ans, f1[i][j]);
    cout << ans << endl;
  }
  return 0;
}
