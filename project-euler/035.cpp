#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#define TOP 1000000
using namespace std;

bitset<TOP> A;
vector<short> B;

int main(){
  for(int i = 2; i*i<=TOP; i++){
    while(A[i]) i++;
    for(int j = i+i; j<=TOP; j+=i) A[j] = 1;
  }
  int ans = 0;
  bool flag;
  for(int i = 2; i<=TOP; i++)
    if(!A[i]){
      flag = 1;
      int j = i;
      B.clear();
      while(j){
	B.push_back(j%10);
	j/=10;
	if(B.back()==0) flag = 0;
      }
      for(short time = 0; time<B.size(); time++){
	if(B.back()!=0){
	  j = 0;
	  for(vector<short>::reverse_iterator k = B.rbegin(); k!=B.rend(); k++)
	    j *= 10, j += *k;
	  if(A[j])
	    flag = 0;
	}
	rotate(B.begin(), B.begin()+1, B.end());
      }
      if(flag)
	ans++;
    }
  cout<<ans<<endl;
  return 0;
}
