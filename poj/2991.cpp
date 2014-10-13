#include<cmath>
#include<iomanip>
#include<iostream>

using namespace std;
const long double PI = 2*acos(.0L), d2r = PI/180;

template<class T, class Oper = plus<T> >class SegmentTree {
  static const int N = 1<<14;
  T *tree;
  Oper oper;
  public:
  inline SegmentTree() : tree(new T[N<<1]) {}
  SegmentTree(int n, T* l) : tree(new T[N<<1]) {
    tree = new T[N<<1];
    copy(l, l+n, tree+N);
    for(int i = N-1; i>0; i--)
      tree[i] = oper(tree[i+i], tree[i+i+1]);
  }
  T query(int lo, int hi, T zero = T()) {
    for(lo += N-1, hi += N+1; lo^hi^1; lo>>=1, hi>>=1) {
      if(~lo&1)
        zero = oper(zero, tree[lo^1]);
      if(hi&1)
        zero = oper(zero, tree[hi^1]);
    }
    return zero;
  }
  inline T getRoot() { return tree[1]; }
  template<class Delt> void modify(int x, Delt delt) {
    x += N;
    tree[x] = delt(tree[x]);
    for(x>>=1; x; x>>=1)
      tree[x] = oper(tree[x+x], tree[x+x+1]);
  }
};

struct Segment {
  double x, y;
  int a;
  Segment(double x = 0, double y = 0, int a = 0) : x(x), y(y), a(a) {
  }
};

inline Segment operator+(Segment a, Segment b) {
  double c = cos(-a.a*PI/180), s = sin(-a.a*PI/180);
  return Segment(a.x+c*b.x-s*b.y, a.y+s*b.x+c*b.y, a.a+b.a);
}

class Change {
  int a;
  public:
  Change(int a) : a(a) {}
  Segment operator()(Segment s) {
    return Segment(s.x*cos((s.a-a)*PI/180)-s.y*sin((s.a-a)*PI/180), s.x*sin((s.a-a)*PI/180)+s.y*cos((s.a-a)*PI/180), a); }
};

int main() {
  ios::sync_with_stdio(false);
  short n, c;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  bool first = true;
  while(cin >> n >> c) {
    if(first)
      first = false;
    else
      cout << '\n';
    Segment *data0 = new Segment[n];
    for(int i = 0; i < n; i++)
      cin >> data0[i].y;
    SegmentTree<Segment> data1(n, data0);
    while(c--) {
      short s, a;
      cin >> s >> a;
      data1.modify(s, Change(180-a));
      Segment ans = data1.getRoot();
      cout << ans.x << ' ' << ans.y << '\n';
    }
  }
  return 0;
}
