#include <iostream>
#include <vector>
using namespace std;
vector<short> p;
int main(){
  short t, n, i;
  cin>>t;
  while(t--){
    cin>>n;
    p.assign(n+1, 0);
    while(n--){
      cin>>p[n];
      short i;
      for(i = n+1; i<p.size() && p[n]-p[i]<i-n; i++);
      cout << i-n << ' ';
    }
    cout<<endl;
  }
  return 0;
}
