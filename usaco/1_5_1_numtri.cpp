/*
PROB: numtri
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
using namespace std;

int a[1000][1000];

int main(){
	freopen("numtri.in", "r", stdin);
	short n;
	cin >> n >> a[0][0];
	for(short i = 1; i<n; i++){
		cin >> a[i][0];
		a[i][0] += a[i-1][0];
		for(short j = 1; j<i; j++){
			cin >> a[i][j];
			a[i][j] += max(a[i-1][j-1], a[i-1][j]);
		}
		cin >> a[i][i];
		a[i][i] += a[i-1][i-1];
	}
	int ans;
	for(short i = 0; i<n; i++) ans = max(ans, a[n-1][i]);
	freopen("numtri.out", "w", stdout);
	cout << ans << endl;
	return 0;
}
