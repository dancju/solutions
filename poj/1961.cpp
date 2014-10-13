#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iostream>
#include<limits>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define endl '\n'

const long double PI = acos(-1.L);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class T> T maximize(T &a, const T &b) { return a = max(a, b); }
template<class T> T minimize(T &a, const T &b) { return a = min(a, b); }

char s[1000001];
long fail[1000001] = {-1};

int main() {
  long len;
  for(int iCase = 1; scanf("%ld", &len), len; iCase++) {
    scanf("%s", s);
    for(long i = 0, j = -1; i<len; )
      if(j==-1 || s[i]==s[j])
        fail[++i] = ++j;
      else
        j = fail[j];
    printf("Test case #%d\n", iCase);
    for(long i = 2; i<=len; i++) {
      long _ = i-fail[i];
      long __ = i/_;
      if(__-1 && !(i%_))
        printf("%ld %ld\n", i, __);
    }
    puts("");
  }
  return 0;
}
