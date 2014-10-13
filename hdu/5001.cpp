#include<cstdio>
#include<vector>

using namespace std;

template<uint8_t N> struct Matrix {
  double val[N][N];
  Matrix(bool x = 0) { memset(val, 0, sizeof val); }
  double* operator[](uint8_t x) { return val[x]; }
  const double* operator[](uint8_t x) const { return val[x]; }
};

template<uint8_t n> inline Matrix<n>
    operator*(const Matrix<n>& a, const Matrix<n>& b) {
  Matrix<n> res;
  for(uint8_t i = 0; i<n; i++)
    for(uint8_t j = 0; j<n; j++)
      if(a[i][j])
        for(uint8_t k = 0; k<n; k++)
          res[i][k] = res[i][k]+a.val[i][j]*b.val[j][k];
  return res;
}

template<class T> T power(const T& a, int n) {
  if(n==1)
    return a;
  T res = power(a, n>>1);
  res = res*res;
  if(n&1)
    res = res*a;
  return res;
}

template<uint8_t N> double sum(const Matrix<N>& m) {
  double res = 0;
  for(int i = 0; i<N; i++)
    for(int j = 0; j<N; j++)
      res += m[i][j];
  return res;
}

vector<short> adj[50];

int main() {
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    int v, e, d;
    scanf("%d%d%d", &v, &e, &d);
    for(int i = 0; i<v; i++)
      adj[i].clear();
    while(e--) {
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a-1].push_back(b-1);
      adj[b-1].push_back(a-1);
    }
    for(int k = 0; k<v; k++) {
      Matrix<50> idt;
      for(int i = 0; i<v; i++)
        if(i!=k)
          for(vector<short>::iterator j = adj[i].begin(); j!=adj[i].end(); j++)
            if(*j != k)
              idt[i][*j] = 1.L/adj[i].size();
      idt = power(idt, d);
      printf("%.10lf\n", sum(idt)/v);
    }
  }
  return 0;
}
