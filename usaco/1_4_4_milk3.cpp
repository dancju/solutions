/*
TASK: milk3
USER: danny_c1
LANG: C++
*/
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

short A[3];
bitset<21> book[21];

void search(vector<short> a){
	for(int i = 0; i<3; i++) cout << a[i] << '\t'; cout << endl;
	short delt;
	for(short i = 0; i<3; i++)
		if(a[i])
			for(short j = 0; j<3; j++)
				if(i!=j && a[j]<A[j]){
					delt = min(a[i], short(A[j]-a[j]));
					a[i] -= delt; a[j] += delt;
					if(!book[a[0]][a[2]]){
						book[a[0]][a[2]] = 1;
						search(a);
					}
					a[i] += delt; a[j] -= delt;
				}
}

int main(){
	freopen("milk3.in", "r", stdin);
	cin >> A[0] >> A[1] >> A[2];
	book[0][A[2]] = 1;
	short a[3] = {0, 0, A[2]};
	search(vector<short>(a, a+3));
	freopen("milk3.out", "w", stdout);
	for(short i = A[2]; i>=0; i--)
		if(book[0][i]){
			for(short j = 0; j<i; j++) if(book[0][j]) cout << j << ' ';
			cout << i << endl;
			break;
		}
	return 0;
}
