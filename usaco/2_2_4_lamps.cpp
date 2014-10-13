/*
  PROG: lamps
  USER: danny_c1
  LANG: C++
*/
#include <bitset>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("lamps.in");
ofstream fout ("lamps.out");

short n, c;
bitset<6> one, oh;
int main(){
  fin >> n >> c;
  short tmp;
  for(fin >> tmp; tmp>0; fin >> tmp)
    one[(tmp-1)%6] = 1;
  for(fin >> tmp; tmp>0; fin >> tmp)
    oh[(tmp-1)%6] = 1;
  if((one&oh)!=0){
    fout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if(c>4)
    c = c&1 ? 3 : 4;
  vector< bitset<6> > A[5];
  A[0].push_back(bitset<6>(string("111111")));
  A[1].push_back(bitset<6>(string("000000")));
  A[1].push_back(bitset<6>(string("101010")));
  A[1].push_back(bitset<6>(string("110110")));
  A[1].push_back(bitset<6>(string("010101")));
  A[2].push_back(bitset<6>(string("000000")));
  A[2].push_back(bitset<6>(string("011100")));
  A[2].push_back(bitset<6>(string("101010")));
  A[2].push_back(bitset<6>(string("001001")));
  A[2].push_back(bitset<6>(string("010101")));
  A[2].push_back(bitset<6>(string("100011")));
  A[2].push_back(bitset<6>(string("111111")));
  A[3].push_back(bitset<6>(string("000000")));
  A[3].push_back(bitset<6>(string("011100")));
  A[3].push_back(bitset<6>(string("101010")));
  A[3].push_back(bitset<6>(string("110110")));
  A[3].push_back(bitset<6>(string("001001")));
  A[3].push_back(bitset<6>(string("010101")));
  A[3].push_back(bitset<6>(string("100011")));
  A[3].push_back(bitset<6>(string("111111")));
  A[4].push_back(bitset<6>(string("000000")));
  A[4].push_back(bitset<6>(string("011100")));
  A[4].push_back(bitset<6>(string("101010")));
  A[4].push_back(bitset<6>(string("110110")));
  A[4].push_back(bitset<6>(string("001001")));
  A[4].push_back(bitset<6>(string("010101")));
  A[4].push_back(bitset<6>(string("100011")));
  A[4].push_back(bitset<6>(string("111111")));
  bool possible = 0;
  for(vector< bitset<6> >::iterator i = A[c].begin(); i<A[c].end(); i++)
    if(((~(*i))&one)==0 && ((*i)&oh)==0){
      possible = 1;
      for(short j = 0; j<n; j++)
	fout << (*i)[j%6];
      fout << endl;
    }
  if(!possible)
    fout << "IMPOSSIBLE" << endl;
  return 0;
}
