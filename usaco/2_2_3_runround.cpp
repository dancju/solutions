/*
PROG: runround
USER: danny_c1
LANG: C++
*/
#include <bitset>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

string b;
bitset<9> c;

bool runround(short d, short p){
	if(d==b.size())
		return (p==0);
	if(c[p])
		return 0;
	if(d==0){
		for(short i = 0; i<b.size(); i++)
			if(c[b[i]] || b[i]==0)
				return 0;
			else
				c[b[i]] = 1;
		c.reset();
	}
	c[p] = 1;
	return runround(d+1, (p+b[p])%b.size());
}

int main(){
	unsigned a;
	fin >> a;
	a++;
	while(1){
		unsigned tmp = a;
		b = "";
		for( ; tmp; tmp /= 10)
			b.insert(0, 1, tmp%10);
		c.reset();
		if(runround(0, 0)) break;
		else a++;
	}
	fout << a << endl;
	return 0;
}
