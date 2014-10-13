/*
TASK: combo
USER: danny_c1
LANG: C++
*/
#include<algorithm>
#include<cstdio>

using namespace std;

int a[3], b[3];

int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);
  int n;
  scanf("%d", &n);
  if(n<=5) {
    printf("%d\n", n*n*n);
    return 0;
  }
  int res = 1;
  scanf("%d%d%d%d%d%d", a, a+1, a+2, b, b+1, b+2);
  for(int i = 0; i<3; i++)
    res *= max(5-min((n+a[i]-b[i])%n, (n+b[i]-a[i])%n), 0);
  printf("%d\n", 2*5*5*5-res);
  return 0;
}
