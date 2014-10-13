#include<iostream>
#include<vector>
using namespace std;

int main(){
  int nCase;
  cin>>nCase;
  for(int cCase = 1; cCase<=nCase; cCase++){
    int n;
    cin>>n;
    vector< vector<char> > g(n+2, vector<char>(n+2));
    for(int i = 1; i<=n; i++)
      for(int j = 1; j<=n; j++)
        cin>>g[i][j];
    for(int i = 1; i<=n; i++)
      for(int j = 1; j<=n; j++)
        if(g[i][j]=='.')
          for(int k = 'A'; k<='Z'; k++)
            if(g[i][j-1]!=k&&g[i][j+1]!=k&&g[i-1][j]!=k&&g[i+1][j]!=k){
              g[i][j] = k;
              break;
            }
    cout<<"Case "<<cCase<<':'<<endl;
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=n; j++)
        cout<<g[i][j];
      cout<<endl;
    }
  }
  return 0;
}
