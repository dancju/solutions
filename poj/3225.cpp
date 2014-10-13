#include<cstdio>

const size_t N = 1<<17;
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

char tree[N<<1] = {0, 1};

inline void pushDown(size_t _) {
  if(tree[_]==3)
    return;
  if(!tree[_]) {
    tree[_<<1] ^= 3;
    tree[_<<1|1] ^= 3;
  } else
    tree[_<<1] = tree[_<<1|1] = tree[_];
  tree[_] = 3;
}

inline void pushUp(size_t _) {
  _ <<= 1;
  if(tree[_]==tree[_|1] && (tree[_]==1 || tree[_]==2))
    tree[_>>1] = tree[_];
}

void update(size_t lo, size_t hi, bool val, size_t _ = 1) {
  if(lo<=left(_) && right(_)<=hi) {
    tree[_] = 1<<val;
    return;
  }
  pushDown(_);
  if(lo<right(_<<1))
    update(lo, hi, val, _<<1);
  if(hi>right(_<<1))
    update(lo, hi, val, _<<1|1);
  pushUp(_);
}

void flip(size_t lo, size_t hi, size_t _ = 1) {
  if(lo<=left(_) && right(_)<=hi) {
    tree[_] ^= 3;
    return;
  }
  pushDown(_);
  if(lo<right(_<<1))
    flip(lo, hi, _<<1);
  if(hi>right(_<<1))
    flip(lo, hi, _<<1|1);
  pushUp(_);
}

int lo, hi;
bool first = 1;

inline void print() {
  if(!~lo)
    return;
  if(first)
    first = 0;
  else
    putchar(' ');
  printf("%c%d,%d%c", lo&1 ? '(' : '[', lo>>1, hi>>1, hi&1 ? ']' : ')');
}

void query(size_t _ = 1) {
  if(!tree[_]) {
    tree[_<<1] ^= 3;
    tree[_<<1|1] ^= 3;
    tree[_] = 3;
    query(_<<1);
    query(_<<1|1);
  } else if(tree[_]==3) {
    query(_<<1);
    query(_<<1|1);
  } else if(tree[_]==2) {
    if(left(_)==hi)
      hi = right(_);
    else {
      print();
      lo = left(_);
      hi = right(_);
    }
  }
}

int main() {
  char o0, o1, o2;
  while(~scanf("%c %c%d,%d%c\n", &o0, &o1, &lo, &hi, &o2)) {
    lo = lo+lo+(o1=='(');
    hi = hi+hi-(o2==')')+1;
    if(o0=='U')
      update(lo, hi, 1);
    else if(o0=='I') {
      update(0, lo, 0);
      update(hi, N, 0);
    } else if(o0=='D')
      update(lo, hi, 0);
    else if(o0=='C') {
      update(0, lo, 0);
      update(hi, N, 0);
      flip(lo, hi);
    } else
      flip(lo, hi);
  }
  lo = hi = -1;
  query();
  print();
  puts(first ? "empty set" : "");
  return 0;
}
