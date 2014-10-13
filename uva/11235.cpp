#include<algorithm>
#include<cmath>
#include<iostream>
#include<limits>
using namespace std;

template<class E, class Comparator>class RMQ {
  int n;
  E *valu;
  int **m;
  Comparator comparator;
  public:
  RMQ(int n, E *valu) {
    this->n = n;
    this->valu = valu;
    m = (int**) malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
      m[i] = (int*) malloc(sizeof(int)*((int)log2(n-i)+1));
      m[i][0] = i;
    }
    for (int j = 1; (1<<j) <= n; j++)
      for (int i = 0; i+(1<<j) <= n; i++)
        if (comparator(valu[m[i][j-1]], valu[m[i+(1<<(j-1))][j-1]]))
          m[i][j] = m[i][j-1];
        else
          m[i][j] = m[i+(1<<(j-1))][j-1];
  }
  int queryIndex(int from, int to) const {
    int i = 0;
    while (from+(1<<(i+1))<=to)
      i++;
    if (comparator(valu[m[from][i]], valu[m[to-(1<<i)][i]]))
      return m[from][i];
    else
      return m[to-(1<<i)][i];
  }
  inline E queryValue(int from, int to) const { return valu[queryIndex(from, to)]; }
};

int main() {
  int n, q;
  while (cin >> n >> q) {
    int top = 0, last = numeric_limits<int>::min(), *index = new int[n], *left = new int[n], *freq = new int[n];
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (top==0 || t!=last) {
        last = t;
        freq[top] = 1;
        left[top] = i;
        top++;
      }
      else
        freq[top-1]++;
      index[i] = top-1;
    }
    RMQ<int, greater<int> > rmq(top, freq);
    while (q--) {
      int from, to;
      cin >> from >> to;
      from--;
      to--;
      int len = index[to]-index[from];
      if (len==0)
        cout << to-from+1 << endl;
      else {
        int result = max(left[index[from]+1]-from, to-left[index[to]]+1);
        if (len > 1)
          result = max(result, rmq.queryValue(index[from]+1, index[to]));
        cout << result << endl;
      }
    }
  }
  return 0;
}
