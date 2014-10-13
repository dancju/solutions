#include <climits>
#include <cstdio>

short n, a[100][100];
int b[100][100][100];

int main(){
  scanf("%hd", &n);
  for(short i = 0; i<n; i++)
    for(short j = 0; j<n; j++)
      scanf("%hd", &a[i][j]);
  for(short k = 0; k<n; k++)
    for(short i = 0; i<n; i++){
      b[k][i][i] = a[i][k];
      for(short j = i+1; j<n; j++)
        b[k][i][j] = b[k][i][j-1]+a[j][k];
    }
  int ans0, ans1 = SHRT_MIN;
  for(short up = 0; up<n; up++)
    for(short down = up; down<n; down++){
      ans0 = 0;
      for(short i = 0; i<n; i++){
        ans0 += b[i][up][down];
        if(ans0<0) ans0 = 0;
        else if(ans0>ans1) ans1 = ans0;
      }
    }
  printf("%d\n", ans1);
  return 0;
}
