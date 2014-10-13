/*
PROG: frac1
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
using namespace std;

short n;

struct frac{ short a, b; };

void print(frac x){ cout << x.a << '/' << x.b << endl; }

void dfs(frac l, frac r){
	if(l.b+r.b>n) return;
	frac mid;
	mid.a = l.a+r.a; mid.b = l.b+r.b;
	dfs(l, mid);
	print(mid);
	dfs(mid, r);
}

int main(){
	freopen("frac1.in", "r", stdin);
	cin >> n;
	frac zero, one;
	zero.a = 0, zero.b = 1;
	one.a = 1, one.b = 1;
	freopen("frac1.out", "w", stdout);
	print(zero);
	dfs(zero, one);
	print(one);
	return 0;
}
