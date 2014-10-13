/*
USER: danny_c1
TASK: contact
LANG: C++
*/
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

short a, b, n;
string S;
vector< pair< int, string > > A, B;
bool compare(pair< int, string > a, pair < int, string > b){
  return a.first>b.first;
}

int main(){
  ifstream fin("contact.in");
  fin >> a >> b >> n;
  string _s;
  while(!fin.eof()){
    S += _s;
    fin >> _s;
  }
  for(short length = a; length<=min((long)b, (long)S.size()); length++){
    A.assign(1<<length, pair< int, string >(0, ""));
    for(int i = 0; i<1<<length; i++)
      A[i].second = bitset<12>(i).to_string().substr(12-length, length);
    for(int i = 0; i<=S.size()-length; i++)
      A[bitset<12>(S.substr(i, length)).to_ulong()].first++;
    B.insert(B.end(), A.begin(), A.end());
  }
  stable_sort(B.begin(), B.end(), compare);
  while(B.back().first==0)
    B.pop_back();
  ofstream fout("contact.out");
  fout << B.front().first << endl << B.front().second;
  short c = 0;
  for(vector< pair< int, string > >::iterator i = B.begin()+1; i!=B.end(); i++){
    if(i->first==(i-1)->first){
      if(c==5){
        fout << endl << i->second;
        c = 0;
      }
      else{
        fout << ' ' << i->second;
        c++;
      }
    }
    else{
      fout << endl << i->first << endl << i->second;
      n--;
      c = 0;
    }
    if(n==1 && i->first!=(i+1)->first)
      break;
  }
  fout << endl;
  return 0;
}
