/*
PROG: inflate
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");

unsigned short v[10000], w[10000];
vector<unsigned> f;

int main(){
  unsigned short lmt, n;
  fin >> lmt >> n;
  lmt++;
  f.assign(lmt, 0);
  for(unsigned short i = 0; i<n; i++)
    fin >> v[i] >> w[i];
  for(unsigned short i = 0; i<n; i++)
    for(unsigned short j = w[i]; j<lmt; j++)
      f[j] = max(f[j], f[j-w[i]]+v[i]);
  fout << f[lmt-1] << endl;
  return 0;
}
