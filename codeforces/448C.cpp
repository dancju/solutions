#include<algorithm>
#include<cstdio>

using namespace std;

int n, a[5000];

int bazinga(int *lo, int *hi, int th) {
  if(lo>=hi)
    return 0;
  if(lo+1==hi)
    return th!=*lo;
  int *m = lo;
  for(int *i = lo+1; i<hi; i++)
    if(*i<*m)
      m = i;
  return  min((int)(hi-lo), *m-th+bazinga(lo, m, *m)+bazinga(m+1, hi, *m));
}

int main() {
  scanf("%d", &n);
  for(int *i = a; i<a+n; i++)
    scanf("%d", i);
  printf("%d\n", bazinga(a, a+n, 0));
  return 0;
}
