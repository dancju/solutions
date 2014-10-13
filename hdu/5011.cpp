#include<cstdio>

int main() {
  int n;
  while(~scanf("%d", &n)) {
    int res = 0;
    while(n--) {
      int _;
      scanf("%d", &_);
      res ^= _;
    }
    puts(res ? "Win" : "Lose");
  }
  return 0;
}