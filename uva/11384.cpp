#include<cstdio>

int main(){
  int n;
  while(~scanf("%d", &n)){
    int ans = 0;
    for(; n; n>>=1)
      ans++;
    printf("%d\n", ans);
  }
  return 0;
}
