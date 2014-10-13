#include<algorithm>
#include<cstring>
#include<cstdio>

typedef long long LLONG;
using namespace std;

short h, w;
LLONG f[2][1<<10];

int main() {
  while(~scanf("%hd%hd", &h, &w)) {
    short s = 0, t = 1;
    if(w > h)
      swap(w, h);
    memset(f, 0, sizeof(f));
    f[0][(1<<w)-1] = 1;
    for(int i = 1; i <= h; i++)
      for(int j = 0; j < w; j++, s^=1, t^=1) {
        memset(f[t], 0, sizeof(f[0]));
        for(int k = 0; k < 1<<w; k++)
          if(f[s][k]) {
            if(k & 1<<(w - 1))
              f[t][k<<1 ^ 1<<w] += f[s][k];
            if(!(k & 1<<(w - 1)))
              f[t][k<<1 ^ 1] += f[s][k];
            if(j && (k & 1<<(w - 1)) && !(k & 1))
              f[t][(k<<1) ^ (1<<w) ^ 3] += f[s][k];
          }
      }
    printf("%lld\n", f[s][(1<<w)-1]);
  }
  return 0;
}
