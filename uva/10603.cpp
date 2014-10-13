#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

short f[201][201];
struct cmp {
  bool operator()(const unsigned short& a, const unsigned short& b) {
    return f[a>>8][a&0xff]>f[b>>8][b&0xff];
  }
};
priority_queue<unsigned short, vector<unsigned short>, cmp> q;
bool inQ[201][201];

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    short t0[3], t1, res0 = 0, res1 = 0;
    scanf("%hd%hd%hd%hd", t0, t0+1, t0+2, &t1);
    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0;
    q.push(0);
    if(t0[2]<=t1) {
      res0 = t0[2];
      res1 = 0;
    }
    while(q.size()) {
      short u[3] = {q.top()>>8, q.top()&0xff};
      u[2] = t0[2]-u[0]-u[1];
      q.pop();
      inQ[u[0]][u[1]] = 0;
      if(res0==t1 && f[u[0]][u[1]]>=res1)
        continue;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
          if(i==j)
            continue;
          short t2 = min(u[i], (short)(t0[j]-u[j])), v[3];
          if(!t2)
            continue;
          v[3^i^j] = u[3^i^j];
          v[i] = u[i]-t2;
          v[j] = u[j]+t2;
          if(f[v[0]][v[1]] > f[u[0]][u[1]]+t2) {
            f[v[0]][v[1]] = f[u[0]][u[1]]+t2;
            for(int k = 0; k < 3; k++)
              if(v[k]<=t1&&(v[k]>res0||(v[k]==res0&&f[v[0]][v[1]]<res1))) {
                res0 = v[k];
                res1 = f[v[0]][v[1]];
              }
            if(res0==t1 && f[v[0]][v[1]]>=res1)
              continue;
            if(!inQ[v[0]][v[1]]) {
              inQ[v[0]][v[1]] = 1;
              q.push(v[0]<<8 | v[1]);
            }
          }
        }
    }
    printf("%hd %hd\n", res1, res0);
  }
  return 0;
}
