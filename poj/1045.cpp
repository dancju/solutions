#include <complex>
#include <iomanip>
#include <iostream>
using namespace std;

int main(){
  double v, r, c, w;
  int n;
  cin>>v>>r>>c>>n;
  cout<<setprecision(3)<<fixed;
  while(n--){
    cin>>w;
    cout<< v*r*c*w/sqrt(1+r*r*c*c*w*w) << endl;
  }
  return 0;
}
