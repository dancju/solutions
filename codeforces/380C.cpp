#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template <class T, int8_t E, class Oper = plus<T>> struct segment_tree {
  static const int N = 1 << E;
  T* tree;
  Oper oper;
  segment_tree() : tree(new T[N * 2]()) { }
  segment_tree(T* l, int n) : tree(new T[N * 2]()) {
    assert(n <= N);
    copy(l, l + n, tree + N);
    for (int i = N - 1; i > 0; i--)
      tree[i] = oper(tree[i + i], tree[i * 2 + 1]);
  }
  ~segment_tree() { delete tree; }
  T query(int lo, int hi, T z_lo = T(), T z_hi = T()) const {
    for (lo += N - 1, hi += N + 1; lo ^ hi ^ 1; lo >>= 1, hi >>= 1) {
      if (~lo & 1)
        z_lo = oper(z_lo, tree[lo ^ 1]);
      if (hi & 1)
        z_hi = oper(tree[hi ^ 1], z_hi);
    }
    return oper(z_lo, z_hi);
  }
  T getRoot() const { return tree[1]; }
  template <class Delt> void modify(int x, Delt delt) {
    x += N;
    tree[x] = delt(tree[x]);
    for (x >>= 1; x; x >>= 1)
      tree[x] = oper(tree[x + x], tree[x + x + 1]);
  }
};

struct segment {
  int32_t t, o, c;
};

segment operator+(const segment& a, const segment& b) {
  int32_t tmp = min(a.o, b.c);
  return segment { a.t + b.t + tmp, a.o + b.o - tmp, a.c + b.c - tmp };
}

const uint8_t E = 20;

segment_tree<segment, E> get_tree() {
  string str;
  cin >> str;
  vector<segment> leaf(str.length());
  for (int i = 0; i < str.size(); i++) {
    switch (str[i]) {
    case '(': leaf[i] = segment { 0, 1, 0 }; break;
    case ')': leaf[i] = segment { 0, 0, 1 }; break;
    default: assert(false);
    }
  }
  segment_tree<segment, E> tree(leaf.data(), leaf.size());
  return tree;
}

int main() {
  auto tree = get_tree();
  int query;
  cin >> query;
  while (query--) {
    int lo, hi;
    cin >> lo >> hi;
    auto res = tree.query(lo - 1, hi - 1).t;
    cout << res * 2 << '\n';
  }
  return 0;
}
