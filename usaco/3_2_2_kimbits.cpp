/*
USER: danny_c1
PROG: kimbits
LANG: C++
*/

#include<cstdio>
#define popCount __builtin_popcountll

using namespace std;

template<class T> inline T lowBit(const T& x) { return x&-x; }

unsigned pascal[32][32], aim;
int N, L;

unsigned count(unsigned s, int b) {
  if(!s)
    return pascal[b][L];
  else if(L<popCount(s))
    return count(s^lowBit(s), 63-__builtin_clzll(lowBit(s)));
  else
    return pascal[b][L-popCount(s)]+count(s^lowBit(s), 63-__builtin_clzll(lowBit(s)));
}

void print(int i, unsigned x) {
  if(!i)
    return;
  print(i-1, x>>1);
  putchar(x&1 ? '1' : '0');
}

int main(){
  for(int i = 0; i<32; i++) {
    pascal[i][0] = pascal[i][i] = 1;
    for(int j = 1; j<i; j++)
      pascal[i][j] = pascal[i-1][j]+pascal[i-1][j-1];
  }
  for(int i = 0; i<32; i++)
    for(int j = 1; j<32; ++j)
      pascal[i][j] += pascal[i][j-1];
  freopen("kimbits.in", "r", stdin);
  freopen("kimbits.out", "w", stdout);
  scanf("%d%d%u", &N, &L, &aim);
  unsigned lo = -1, hi = 1LL<<N;
  while(lo+1<hi) {
    unsigned mid = (lo+hi)>>1;
    if(count(mid, 0)<aim)
      lo = mid;
    else
      hi = mid;
  }
  print(N, hi);
  puts("");
  return 0;
}