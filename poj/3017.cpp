#include<cstdio>
#include<deque>

using namespace std;

template<class T> inline void minimize(T& a, const T& b) { if(a>b) a = b; }

const int N = 1e5;

int n, a[N+1];
long long limit;

inline bool bazinga0() {
  bool res = 1;
  for(int i = 1; i<=n; i++) {
    scanf("%d", a+i);
    if(a[i]>limit)
      res = 0;
  }
  return res;
}

long long f[N+1];

inline void bazinga1() {
  long long sum = 0;
  deque<int> deq;
  for(int i = 1, j = 1; i<=n; i++) {
    sum += a[i];
    while(sum>limit)
      sum -= a[j++];
    while(deq.size() && a[i]>=a[deq.back()])
      deq.pop_back();
    deq.push_back(i);
    while(deq.front()<j)
      deq.pop_front();
    f[i] = f[j-1]+a[deq.front()];
    for(deque<int>::iterator j = deq.begin(); j+1!=deq.end(); j++)
      minimize(f[i], f[j[0]]+a[j[1]]);
  }
}

int main() {
  while(~scanf("%d%lld", &n, &limit)) {
    if(bazinga0()) {
      bazinga1();
      printf("%lld\n", f[n]);
    } else
      puts("-1");
  }
  return 0;
}
