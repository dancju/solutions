#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

typedef long long LLONG;
using namespace std;

template<class E> struct SquareMatrix {
  int n;
  E **val;
  E*& operator[](int i) const { return val[i]; }
};

template<class E> SquareMatrix<E> constructSquareMatrix(int n) {
  SquareMatrix<E> res;
  res.n = n;
  res.val = new E*[n];
  for(int i = 0; i < n; i++) {
    res[i] = new E[n];
    memset(res[i], 0, sizeof(E)*n);
  }
  return res;
}

template<class E> SquareMatrix<E> identityMatrix(int n) {
  SquareMatrix<E> res;
  res.n = n;
  res.val = new E*[n];
  for(int i = 0; i < n; i++) {
    res[i] = new E[n];
    memset(res[i], 0, sizeof(E)*n);
    res[i][i] = 1;
  }
  return res;
}

template<class E>
SquareMatrix<E>
add(const SquareMatrix<E>& a, const SquareMatrix<E>& b, LLONG mod) {
  assert(a.n == b.n);
  int n = a.n;
  SquareMatrix<E> res = constructSquareMatrix<E>(n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      res[i][j] = (a[i][j]+b[i][j])%mod;
  return res;
}

template<class E>
SquareMatrix<E>
multiply(const SquareMatrix<E>& a, const SquareMatrix<E>& b, LLONG mod) {
  assert(a.n == b.n);
  int n = a.n;
  SquareMatrix<E> res = constructSquareMatrix<E>(n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++) {
        res[i][j] += ((LLONG)a[i][k] * b[k][j])%mod;
        res[i][j] %= mod;
      }
  return res;
}

//===============================END OF TEMPLATE ===============================

SquareMatrix<int> A[29], B[30];

void print(const SquareMatrix<int>& sm) {
  for(int i = 0; i < sm.n; i++) {
    for(int j = 0; j < sm.n-1; j++)
      printf("%d ", sm[i][j]);
    printf("%d\n", sm[i][sm.n-1]);
  }
}

int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  A[0] = constructSquareMatrix<int>(n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      scanf("%d", &A[0][i][j]);
      A[0][i][j] %= m;
    }
  for(int i = 1; i < 29; i++)
    A[i] = multiply(A[i-1], A[i-1], m);
  B[0] = A[0];
  for(int i = 1; i < 30; i++)
    B[i] = add(B[i-1], multiply(A[i-1], B[i-1], m), m);
  SquareMatrix<int> res = constructSquareMatrix<int>(A[0].n),
    t0 = identityMatrix<int>(n);
  for(int i = 0; k; i++, k>>=1)
    if(k&1) {
      res = add(res, multiply(t0, B[i], m), m);
      t0 = multiply(t0, A[i], m);
    }
  print(res);
  return 0;
}
