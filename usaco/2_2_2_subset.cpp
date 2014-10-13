/*
PROG: subset
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	short n;
	cin >> n;
	if((((n+1)*n/2)&1)==1 || n==1){
		cout << 0 << endl;
		return 0;
	}
	vector<long long> f((((n+1)*n)>>2)+1, 0);
	f.front() = 1;
	for(short i = 1; i<=n; i++)
		for(short j = ((n+1)*n)>>2; j>=i; j--)
			f[j] += f[j-i];
	cout << (f.back()>>1) << endl;
	return 0;
}
