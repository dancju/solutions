#include<iostream>
#include<limits>
using namespace std;

int main(){
  int nCase;
  cin>>nCase;
  while(nCase--){
    int n, t, m = numeric_limits<int>::min(), ans = numeric_limits<int>::min();
    cin>>n;
    cin>>m;
    while(--n){
      cin>>t;
      ans = max(ans, m-t);
      m = max(m, t);
    }
    cout<<ans<<endl;
  }
  return 0;
}
