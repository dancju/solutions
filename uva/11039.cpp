#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

inline bool greaterAbsoluteValue(const int &a, const int &b){ return abs(a)<abs(b); }

inline int sgn(const int &x){
  if(x>0)
    return 1;
  else if(x<0)
    return -1;
  else
    return 0;
}

int main(){
  int nCase;
  cin>>nCase;
  while(nCase--){
    int nD;
    cin>>nD;
    vector<int> d(nD);
    for(vector<int>::iterator i = d.begin(); i!=d.end(); i++)
      cin>>*i;
    sort(d.begin(), d.end(), greaterAbsoluteValue);
    int ans = 1;
    for(vector<int>::iterator i = d.begin(); i!=d.end()-1; i++)
      if(sgn(*i)!=sgn(*(i+1)))
      ans++;
    cout<<ans<<endl;
  }
  return 0;
}
