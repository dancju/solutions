/*
PROG: sort3
USER: danny_c1
LANG: C++
*/
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

short n, ans, A[1000], B[3], C[3][3];

int main(){
	freopen("sort3.in", "r", stdin);
	cin >> n;
	for(short* i = A; i<A+n; i++){
		cin >> *i;
		(*i)--;
		B[*i]++;
	}
	for(short* i = A; i<A+B[0]; i++)
		C[0][*i]++;
	for(short* i = A+B[0]; i<A+B[0]+B[1]; i++)
		C[1][*i]++;
	for(short* i = A+B[0]+B[1]; i<A+B[0]+B[1]+B[2]; i++)
		C[2][*i]++;
	for(short i = 0; i<2; i++)
		for(short j = i+1; j<3; j++)
			if(i!=j){
				ans += min(C[i][j], C[j][i]);
				C[i][j] -= C[j][i];
				C[j][i] = 0;
			}
	ans += abs(C[1][0]+C[0][1])*2;
	freopen("sort3.out", "w", stdout);
	cout << ans << endl;
	return 0;
}
