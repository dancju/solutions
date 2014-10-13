/*
PROG: zerosum
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

short N;

void dfs(int a, char o, int b, string s){
	if(b%10==N){
		if(o=='+')
			a += b;
		else
			a -= b;
		if(a==0)
			fout << s << endl;
	}
	else{
		dfs(a, o, b*10+b%10+1, s+' '+char(b%10+'1'));
		if(o=='+')
			a += b;
		else
			a -= b;
		dfs(a, '+', b%10+1, s+'+'+char(b%10+'1'));
		dfs(a, '-', b%10+1, s+'-'+char(b%10+'1'));
	}
}

int main(){
	fin >> N;
	dfs(0, '+', 1, "1");
	return 0;
}
