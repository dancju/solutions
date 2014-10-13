#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

inline bool cmp(const string &a, const string &b){ return a+b>b+a; }

int main(){
  short n;
  while(cin>>n, n){
    vector<string> data(n);
    for(vector<string>::iterator i = data.begin(); i!=data.end(); i++)
      cin>>*i;
    sort(data.begin(), data.end(), cmp);
    for(vector<string>::iterator i = data.begin(); i!=data.end(); i++)
      cout<<*i;
    cout<<endl;
  }
  return 0;
}
