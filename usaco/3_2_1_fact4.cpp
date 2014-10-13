/*
PROG: fact4
USER: danny_c1
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

int main(){
	unsigned short n;
	unsigned ans = 1;
	fin >> n;
	n++;
	while(--n){
		ans *= n;
		while(ans%10==0)
			ans /= 10;
		ans %= 1000;
	}
	fout << ans%10 << endl;
	return 0;
}
