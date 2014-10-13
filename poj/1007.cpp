#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< pair< string, int > > A;
bool compare(pair< string, int > a, pair< string, int > b){
  return a.second < b.second;
}

int main(){
  short n, m;
  cin >> n >> m;
  A.assign(m, pair< string, int >("", 0));
  for(vector< pair< string, int > >::iterator k = A.begin(); k!=A.end(); k++){
    cin >> k->first;
    for(string::iterator i = k->first.begin(); i!=k->first.end(); i++)
      for(string::iterator j = i+1; j!=k->first.end(); j++)
        k->second += (*i)>(*j);
  }
  sort(A.begin(), A.end(), compare);
  for(vector< pair< string, int > >::iterator k = A.begin(); k!=A.end(); k++)
    cout << k->first << endl;
  return 0;
}
