/*
PROG: money
LANG: C++
USER: danny_c1
*/
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");

short V, N, v;
vector<long long> f;

int main(){
	fin >> V >> N;
	f.assign(N+1, 0);
	f.front() = 1;
	while(V--){
		fin >> v;
		for(vector<long long>::iterator i = f.begin()+v; i<f.end(); i++)
			*i += *(i-v);
	}
	fout << f.back() << endl;
	return 0;
}
