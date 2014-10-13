#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  while(cin>>n){
    vector<long long> x(n);
    long long a = 0;
    for(vector<long long>::iterator i = x.begin(); i!=x.end(); i++){
      cin>>*i;
      a += *i;
    }
    a /= n;
    x.front() -= a;
    for(vector<long long>::iterator i = x.begin()+1; i!=x.end(); i++){
      *i -= a;
      *i += *(i-1);
    }
    sort(x.begin(), x.end());
    a = x[n/2];
    long long ans = 0;
    for(vector<long long>::iterator i = x.begin(); i!=x.end(); i++)
      ans += abs(a-*i);
    cout<<ans<<endl;
  }
  return 0;
}
