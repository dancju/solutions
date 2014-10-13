/*
PROG: fracdec
USER:
LANG: C++
*/
#include <bitset>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int N, D;
stringstream S; 
vector<int> A, B;
bitset<100000> C(0);

int main(){
  fin >> N >> D;
  S << N/D << '.';
  N %= D;
  if(N==0)
    S << 0;
  while(C[N]==0){
    C[N] = 1;
    B.push_back(N);
    N *= 10;
    A.push_back(N/D);
    N %= D;
  }
  unsigned short i = 0;
  while(B[i]!=N)
    S << A[i++];
  if(N){
    S << '(';
    while(i<A.size())
      S << A[i++];
    S << ')';
  }
  S << endl;
  string str;
  S >> str;
  unsigned st = 0;
  while (st < str.length()) fout << str.substr(st, 76) << endl, st+= 76;
  return 0;
}

