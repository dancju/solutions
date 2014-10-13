#include<iostream>
using namespace std;

int main(){
  int cCase = 0, n;
  while(cin>>n, n>0){
    n--;
    int ans = 0;
    for(; n; n>>=1)
      ans++;
    cout<<"Case "<<++cCase<<": "<<ans<<endl;
  }
  return 0;
}
