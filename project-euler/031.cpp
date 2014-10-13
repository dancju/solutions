#include <iostream>
#include <vector>
using namespace std;

short coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};

vector<int> f(201, 0);

int main(){
  f[0] = 1;
  for(short* j = coin; j<coin+8; j++)
    for(short i = *j; i<=200; i++)
      f[i] += f[i-*j];
  cout<<f[200]<<endl;
  return 0;
}
