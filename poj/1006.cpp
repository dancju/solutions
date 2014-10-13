#include <iostream>
using namespace std;

int main(){
  short a, b, c, d;
  cin >> a >> b >> c >> d;
  for(int i = 1; a!=-1; i++){
    unsigned long ans = (5544*a+14421*b+1288*c+21252-d)%21252;
    if(ans==0) ans = 21252;
    cout << "Case " << i << ": the next triple peak occurs in " << ans << " days." << endl;
    cin >> a >> b >> c >> d;
  }
  return 0;
}
