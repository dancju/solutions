/*
USER: danny_c1
PROG: stamps
LANG: C++
*/
#include <fstream>
#include <limits>
#include <deque>
using namespace std;

int main(){
  short n, k;
  ifstream fin("stamps.in");
  fin >> k >> n;  
  deque<short> a(n, 0);
  for(deque<short>::iterator i = a.begin(); i!=a.end(); i++)
    fin >> *i;
  deque<int> b(10000*k, numeric_limits<int>::max());
  b.front() = 0;
  deque<int>::iterator i;
  for(i = b.begin(); *i<=k; i++)
    if(*i<k)
      for(deque<short>::iterator j = a.begin(); j!=a.end(); j++)
	*(i+*j) = min(*(i+*j), (*i)+1);
  ofstream fout("stamps.out");
  fout << i-b.begin()-1 << endl;
  return 0;
}
