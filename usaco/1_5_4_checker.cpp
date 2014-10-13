/*
PROG: checker
LANG: C++
USER: danny_c1
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

short n;
int one, ans, out;
vector<short> memo;

void search(int down, int forward, int back){
  if(down==one){
    ans++;
    if(out!=3){
      for(vector<short>::iterator i = memo.begin(); i<memo.end()-1; i++) cout << *i+1 << ' ';
      cout << memo.back()+1 << endl;
      out++;
    }
    return;
  }
  forward <<= 1; forward &= one;
  back >>= 1; back &= one;
  int tmp = down|forward|back;
  for(short i = 0; i<n; i++)
    if(1<<i & (~tmp)){
      if(out!=3) memo.push_back(i);
      search(down|1<<i, forward|1<<i, back|1<<i);
      if(out!=3) memo.pop_back();
    }
}

int main(){
  freopen("checker.in", "r", stdin);
  cin >> n;
  one = (1<<n)-1;
  freopen("checker.out", "w", stdout);
  search(0, 0, 0);
  cout << ans << endl;
  return 0;
}
