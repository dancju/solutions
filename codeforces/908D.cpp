#include<iostream>

using namespace std;

const int MOD = 1000000007;

int bin(int a, long long deg) {
	int r = 1;
	while (deg) {
		if (deg & 1)
			r = 1LL*r*a%MOD;
		deg >>= 1;
		a = 1LL*a*a%MOD;
	}
	return r;
}

inline int inverse(int x) {
	return bin(x, MOD-2);
}

int pa, pb, d[1001][2001];

int main() {
	int k;
	cin >> k >> pa >> pb;
	int sum = pa+pb;
	sum = inverse(sum);
	pa = 1LL*pa*sum%MOD;
	pb = 1LL*pb*sum%MOD;
	for (int i = k; i>=0; i--)
		for (int j = max(k, k+k-i-i); j>=0; j--)
			if (j>=k)
				d[i][j] = j;
			else if (i+j>=k)
				d[i][j] = (1LL*pa*inverse(pb)%MOD+i+j)%MOD;
			else
				d[i][j] = (1LL*pa*d[i+1][j]%MOD+1LL*pb*d[i][i+j]%MOD)%MOD;
	cout << d[1][0] << endl;
	return 0;
}
