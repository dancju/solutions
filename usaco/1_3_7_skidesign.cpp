/*
ID: danny_c1
PROG: skidesign
LANG: C++11
*/

#include<array>
#include<fstream>
#include<limits>

using namespace std;

int main() {
  ifstream in("skidesign.in");
  ofstream out("skidesign.out");
  int n;
  array<int16_t, 101> a{};
  in >> n;
  for (int i = 0; i<n; i++) {
    int _;
    in >> _;
    a[_]++;
  }
  int res = numeric_limits<int>::max();
  for (int l = 0; l+17<=100; l++) {
    int r = l+17;
    int val = 0;
    for (int i = 0; i<l; i++)
      val += a[i]*(l-i)*(l-i);
    for (int i = 100; i>r; i--)
      val += a[i]*(i-r)*(i-r);
    res = min(res, val);
  }
  out << res << '\n';
  return 0;
}
