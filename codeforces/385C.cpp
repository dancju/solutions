#include<algorithm>
#include<cmath>
#include<iostream>
#define FOR(i,b,e) for(__typeof(b)i=(b);i!=(e);i++)

using namespace std;
const int N = 0x200;

int prime[N], expo[N], x[1000001];

int main() {
  ios::sync_with_stdio(false);
  prime[0] = 2;
  for(int i = 1; i < N; i++) {
    for(prime[i] = prime[i-1]+1; ; prime[i]++) {
      bool mark = true;
      for(int j = 0; j < i; j++)
        if(prime[i]%prime[j] == 0) {
          mark = false;
          break;
        }
      if(mark)
        break;
    }
  }
  int n;
  cin >> n;
  FOR(j, 0, n) {
    cin >> x[j];
    for(int i = 0; x[j]!=1 && i<N; i++) {
      if(x[j]%prime[i] == 0)
        expo[i]++;
      while(x[j]%prime[i] == 0)
        x[j] /= prime[i];
    }
  }
  sort(x, x+n);
  FOR(i, 1, N)
    expo[i] += expo[i-1];
  int m;
  cin >> m;
  while(m--) {
    int l, r;
    cin >> l >> r;
    int a = upper_bound(x, x+n, r)-lower_bound(x, x+n, l);
    l = lower_bound(prime, prime+N, l)-prime;
    r = upper_bound(prime, prime+N, r)-prime;
    a += expo[r-1];
    if(l)
      a -= expo[l-1];
    cout << a << '\n';
  }
  return 0;
}