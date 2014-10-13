#include <cstdio>

int A[100001];

int main() {
  int n, w;
  short k;
  scanf("%d%hd%d", &n, &k, &w);
  for(int i = k; i < n+k; i++) {
    scanf("%1d", &A[i]);
    A[i] += A[i-k];
  }
  while(w--) {
    int l, r, ans = 0;
    scanf("%d%d", &l, &r);
    l += k-1;
    r += k-1;
    for(short i = 0; i < k-1; i++)
      ans += A[r-k+1+i]-A[l+i-k];
    ans += (r-l+1)/k;
    ans -= A[r]-A[l-1];
    printf("%d\n", ans);
  }
  return 0;
}
