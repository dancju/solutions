#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

vector< short > A;
int n, sum, length;
bitset<64> B;

bool dfs(int a, short b, short i){
  if(a==0 && b==0)
    return true;
  else if(length==b){
    while(B[i]) i++;
    B[i] = 1;
    bool tmp = dfs(a, b-A[i], i);
    B[i] = 0;
    return tmp;
  }
  else if(b==0)
    return dfs(a-1, length, 1);
  else{
    for(; i<n; i++)
      if(A[i]<=b && B[i]==0 && (i==0 || A[i]!=A[i-1] || B[i-1])){
        B[i] = 1;
        bool tmp = dfs(a, b-A[i], i);
        B[i] = 0;
        if(tmp) return true;
      }
    return false;
  }
}

int main(){
  cin >> n;
  while(n!=0){
    A.assign(n, 0);
    sum = 0;
    for(vector< short >::iterator i = A.begin(); i!=A.end(); i++){
      cin >> *i;
      sum += *i;
    }
    sort(A.begin(), A.end(), greater< short > ());
    for(length = A.front(); length<=sum; length++)
      if(sum%length==0 && dfs(sum/length-1, length, 0)){
        cout << length << endl;
        break;
      }
    cin >> n;
  }
  return 0;
}
