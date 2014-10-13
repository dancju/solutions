#include<iostream>
using namespace std;

inline char nextChar() {
  char t;
  cin >> t;
  return t;
}

inline short nextShort() {
  short t;
  cin >> t;
  return t;
}

int main() {
  ios::sync_with_stdio(false);
  short a[1000][1000], b[1000][1000], c[1000][1000];
  short nCase = nextShort();
  while (nCase--) {
    short m = nextShort(), n = nextShort();
    int resu = 0;
    for (short i = 0; i < m; i++) {
      for (short j = 0; j < n; j++) {
        a[i][j] = b[i][j] = c[i][j] = nextChar()=='F' ? 1 : 0;
        if (a[i][j] && i && a[i-1][j]!=0)
          a[i][j] = a[i-1][j]+1;
        if (j && a[i][j] && a[i][j-1]>=a[i][j])
          b[i][j] = b[i][j-1]+1;
      }
      for (short j = n-2; j >= 0; j--) {
        if (c[i][j] && a[i][j+1]>=a[i][j])
          c[i][j] = c[i][j+1]+1;
        resu = max(resu, a[i][j]*(b[i][j]+c[i][j]-1));
      }
    }
    cout << resu*3 << '\n';
  }
}
