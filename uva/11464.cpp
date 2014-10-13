#include<iostream>
#include<limits>
#include<vector>
using namespace std;

inline bool bit(int a, int b){ return (a&(1<<b))>>b; }

int main(){
  int nCase, n;
  cin>>nCase;
  for(int cCase = 1; cCase<=nCase; cCase++){
    cin>>n;
    vector<int> A(n+1, 0);
    for(int i = 1; i<=n; i++)
      for(int j = 1; j<=n; j++){
        bool t;
        cin>>t;
        A[i] |= (1&t)<<j;
      }
    int ans = numeric_limits<int>::max();
    for(int first = 0; first<(1<<n+1); first+=2){
      vector<int> B(n+1, 0);
      B[1] = first;
      for(int i = 2; i<=n; i++)
        for(int j = 1; j<=n; j++)
          B[i] |= (1&(bit(B[i-1], j-1)^bit(B[i-1], j+1)^bit(B[i-2], j)))<<j;
      bool t = 1;
      int thisAns = 0;
      for(int i = 1; i<=n; i++){
        if(A[i]&(~B[i])){
          t = 0;
          break;
        }
        B[i] ^= A[i];
        B[i] = (B[i]&0x5555) + ((B[i]&0xaaaa)>>1);
        B[i] = (B[i]&0x3333) + ((B[i]&0xcccc)>>2);
        B[i] = (B[i]&0x0f0f) + ((B[i]&0xf0f0)>>4);
        B[i] = (B[i]&0x00ff) + ((B[i]&0xff00)>>8);
        thisAns += B[i];
      }
      if(t)
        ans = min(ans, thisAns);
    }
    cout<<"Case "<<cCase<<": "<<(ans==numeric_limits<int>::max() ? -1 : ans)<<endl;
  }
  return 0;
}
