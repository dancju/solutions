#include<iostream>
#include<vector>
using namespace std;

long long f(vector<short> & p, int i, int target){
  if(i==-1)
    return 0;
  if(p[i]==target)
    return f(p, i-1, target);
  return f(p, i-1, 6-p[i]-target)+(1ll<<i);
}

int main(){
  int cCase = 0, n;
  while(cin>>n, n){
    vector<short> a(n), b(n);
    for(int i = 0; i<n; i++)
      cin>>a[i];
    for(int i = 0; i<n; i++)
      cin>>b[i];
    int k = n-1;
    while(k>=0 && a[k]==b[k])
      k--;
    long long ans = 0;
    if(k>=0){
      int other = 6-a[k]-b[k];
      ans = f(a, k-1, other)+f(b, k-1, other)+1;
    }
    cout<<"Case "<<++cCase<<": "<<ans<<endl;
  }
  return 0;
}
