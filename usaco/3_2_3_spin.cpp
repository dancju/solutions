/*
ID: danny_c1
PROG: spin
LANG: C++11
*/

#include<array>
#include<bitset>
#include<fstream>

using namespace std;

int main() {
  ifstream in("spin.in");
  ofstream out("spin.out");
  array<bitset<360>, 5> wheels;
  array<int, 5> speeds;
  for (int i = 0; i<5; i++) {
    int n;
    in >> speeds[i] >> n;
    while (n--) {
      int lo, size;
      in >> lo >> size;
      if (lo+size >= 360) {
        for (int j = lo; j<360; j++)
          wheels[i][j] = 1;
        for (int j = 0; j<=lo+size-360; j++)
          wheels[i][j] = 1;
      } else {
        for (int j = lo; j<=lo+size; j++)
          wheels[i][j] = 1;
      }
    }
  }
  for (int time = 0; time<360; time++) {
    if ((wheels[0] & wheels[1] & wheels[2] & wheels[3] & wheels[4]).any()) {
      out << time << '\n';
      return 0;
    }
    for(int i = 0; i<5; i++)
      wheels[i] = wheels[i]<<speeds[i] | wheels[i]>>(360-speeds[i]);
  }
  out << "none\n";
  return 0;
}
