#include<algorithm>
#include<cstdio>
using namespace std;

int w, vH, n, x[100000], y[100000];
int vV;

bool possible(){
  double left = x[0], right = x[0]+w;
  for(int i = 1; i<n; i++){
    double delta = (double)vH*(y[i]-y[i-1])/vV;
    left = max(left-delta, (double)x[i]);
    right = min(right+delta, (double)x[i]+w);
    if(left>right)
      return false;
  }
  return true;
}

int main(){
  int nCase;
  scanf("%d", &nCase);
  while(nCase--){
    scanf("%d%d%d", &w, &vH, &n);
    for(int i = 0; i<n; i++)
      scanf("%d%d", &x[i], &y[i]);
    int left = 0, right = 1000001;
    while(right-left!=1){
      vV = (left+right)>>1;
      *(possible() ? &left : &right) = vV;
    }
    vV = left;
    int nV, t, ans = 0;
    scanf("%d", &nV);
    while(nV--){
      scanf("%d", &t);
      if(t<=vV)
        ans = max(ans, t);
    }
    ans ? printf("%d\n", ans) : printf("IMPOSSIBLE\n");
  }
  return 0;
}
