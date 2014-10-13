#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> dragon, knight;

int main(){
  int n, m;
  while(cin>>n>>m, n){
    dragon.resize(n);
    knight.resize(m);
    for(vector<int>::iterator i = dragon.begin(); i!=dragon.end(); i++)
      cin>>*i;
    for(vector<int>::iterator i = knight.begin(); i!=knight.end(); i++)
      cin>>*i;
    sort(dragon.begin(), dragon.end());
    sort(knight.begin(), knight.end());
    int ans = 0;
    vector<int>::iterator i, j;
    for(i = dragon.begin(), j = knight.begin(); i!=dragon.end() && j!=knight.end(); j++)
      if(*j >= *i){
        ans += *j;
        i++;
      }
    if(i==dragon.end())
      cout<<ans<<endl;
    else
      cout<<"Loowater is doomed!"<<endl;
  }
  return 0;
}
