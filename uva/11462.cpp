#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  while(cin>>n, n){
    vector<short> a(100, 0);
    int x;
    while(n--){
      cin>>x;
      a[x]++;
    }
    int i = 0;
    while(a[++i]==0);
    cout<<i;
    for(int j = 1; j<a[i]; j++)
      cout<<' '<<i;
    for(i = i+1; i<100; i++)
      for(int j = 0; j<a[i]; j++)
        cout<<' '<<i;
    cout<<endl;
  }
  return 0;
}
