/*
PROG: nocows
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("nocows.in");
ofstream fout("nocows.out");

int main(){
	unsigned N, K;
	fin >> N >> K;
	vector< vector<unsigned> > F(K+1, vector<unsigned>(N+1, 0));
	F[1][1] = 1;
	for(unsigned k = 2; k<=K; k++)
		for(unsigned n = 3; n<=N; n+=2){
			for(unsigned n0 = 1; n0<n-1; n0+=2)
				if(F[k-1][n-n0-1]){
					F[k][n] += F[k-1][n0]*F[k-1][n-1-n0];
					F[k][n] %= 9901;
					for(unsigned k0 = 1; k0<k-1; k0++)
						if(F[k0][n0]){
							F[k][n] += F[k0][n0]*F[k-1][n-n0-1]*2;
							F[k][n] %= 9901;
						}
				}
		}
	fout << F[K][N] << endl;
	return 0;
}
