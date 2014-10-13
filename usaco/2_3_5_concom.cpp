/*
PROG: concom
LANG: C++
USER: danny_c1
*/
#include <bitset>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");

vector< vector<short> > A(100, vector<short>(100, 0));
bitset<100> B(0);
vector< bitset<100> > C(100, bitset<100>(0));

void dfs(short x){
  if(B[x])
    return;
  B[x] = 1;
  for(short i = 0; i<100; i++)
    if(A[x][i]>50){
      C[x][i] = 1;
      dfs(i);
      for(short j = 0; j<100; j++)
        if(A[i][j] && x!=j){
          A[x][j] += A[i][j];
          A[i][j] = 0;
          if(A[x][j]>50)
            B[x] = 0;
        }
    }
  dfs(x);
}

int main(){
  short n;
  fin >> n;
  for(short s, t; n--; fin >> A[s-1][t-1], s==t ? A[s-1][t-1] = 0 :0)
    fin >> s >> t;
  for(short i = 0; i<100; i++)
    dfs(i);
  for(short i = 0; i<100; i++)
    for(short j = 0; j<100; j++)
      if(C[i][j])
        fout << i+1 << ' ' << j+1 << endl;
  return 0;
}
