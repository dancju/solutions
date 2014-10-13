/*
PROG: comehome
USER: danny_c1
LANG: C++
*/
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("comehome.in");
ofstream fout("comehome.out");

inline short map(char x){ return x<'a' ? x-'A' : x-'a'+26; }
vector< vector<int> > B(52, vector<int>(52, 0xFFFFFFF));

int main(){
  short p;
  fin >> p;
  while(p--){
    char a, b; int w;
    fin >> a >> b >> w;
    B[map(a)][map(b)] = B[map(b)][map(a)] = min(B[map(a)][map(b)], w);
  }
  for(short k = 0; k<52; k++)
    for(short i = 0; i<52; i++)
      for(short j = 0; j<52; j++)
        B[i][j] = min(B[i][j], B[i][k]+B[k][j]);
  short ans0;
  int ans1 = 0xFFFFFFF;
  for(short i = 0; i<25; i++)
    if(ans1>B[i][25])
      ans0 = i, ans1 = B[i][25];
  fout << char(ans0+'A') << ' ' << ans1 << endl;
  return 0;
}
