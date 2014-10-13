#include<cstdio>

typedef long long llong;

const size_t N = 1<<17;
inline size_t x(size_t _) { return 63-__builtin_clzll(_); }
inline size_t y(size_t _) { return _-(1<<x(_)); }
inline size_t length(size_t _) { return N>>x(_); }
inline size_t left(size_t _) { return y(_)*length(_); }
inline size_t right(size_t _) { return (1+y(_))*length(_); }

struct Segment {
	llong sum;
	int add;
} tree[N<<1];

inline void sink(size_t _) {
	int t = tree[_].add;
	if(!t)
		return;
	tree[_].add = 0;
	tree[_].sum += (llong)t*length(_);
	if(N<=_)
		return;
	tree[_<<1].add += t;
	tree[_<<1|1].add += t;
}

llong sum(size_t _, size_t lo, size_t hi) {
	sink(_);
	if(lo<=left(_) && right(_)<=hi)
		return tree[_].sum;
	llong res = 0;
	if(lo<right(_<<1))
		res += sum(_<<1, lo, hi);
	if(right(_<<1)<hi)
		res += sum(_<<1|1, lo, hi);
	return res;
}

inline void add(size_t lo, size_t hi, int val) {
	llong t0 = 0, t1 = 0;
	for(lo += N-1, hi += N; lo^hi^1; lo>>=1, hi>>=1) {
		if(~lo&1) {
			tree[lo^1].add += val;
			t0 += (llong)val*length(lo^1);
		}
		if(hi&1) {
			tree[hi^1].add += val;
			t1 += (llong)val*length(hi^1);
		}
		tree[lo>>1].sum += t0;
		tree[hi>>1].sum += t1;
	}
	t0 += t1;
	for(lo>>=1; lo; lo>>=1)
		tree[lo].sum += t0;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = N; i<N+n; i++)
		scanf("%lld", &tree[i].sum);
	for(int i = N-1; i; i--)
		tree[i].sum = tree[i<<1].sum+tree[i<<1|1].sum;
	while(q--) {
		char _;
		int lo, hi, val;
		scanf("%*c%c", &_);
		if(_=='Q') {
			scanf("%d%d", &lo, &hi);
			printf("%lld\n", sum(1, lo-1, hi));
		} else {
			scanf("%d%d%d", &lo, &hi, &val);
			add(lo-1, hi, val);
		}
	}
 	return 0;
}