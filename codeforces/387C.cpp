#include<cstdio>
#include<cstring>

const int N = 100000;

char s[N];

int cmp(int i, int l1, int j, int l2) {
  if(l1 != l2)
    return l1-l2;
  for(int repp = 0; repp < l1; ++repp) {
    if(s[i] != s[j])
      return s[i]-s[j];
    ++i, ++j;
  }
  return 0;
}

int main() {
  int ans = 0;
  scanf("%s", s);
  for(int i = strlen(s)-1; i>=0; i--) {
    int j = i;
    while(j>=0 && s[j]=='0')
      --j;
    ++ans;
    if(j == 0)
      break;
    if(cmp(0, j, j, i-j+1) < 0)
      break;
    i = j;
  }
  printf("%d\n", ans);
  return 0;
}