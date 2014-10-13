/*
USER: danny_c1
LANG: C++11
PROG: ratios
*/

#include<cstring>
#include<fstream>

using namespace std;

int16_t a[3][3], y[3], x[3], _y[3];

int main() {
  ifstream in("ratios.in");
  ofstream out("ratios.out");
  in >> y[0] >> y[1] >> y[2];
  for (int i = 0; i<3; i++)
    for (int j = 0; j<3; j++)
      in >> a[j][i];
  for (x[0] = 0; x[0] < 100; x[0]++)
    for (x[1] = 0; x[1] < 100; x[1]++)
      for (x[2] = 0; x[2] < 100; x[2]++) {
        if (x[0]==0 && x[1]==0 && x[2]==0)
          continue;
        memset(_y, 0, sizeof _y);
        for (int i = 0; i<3; i++)
          for(int j = 0; j<3; j++)
            _y[i] += a[i][j]*x[j];
        if (y[1]*_y[0]!=_y[1]*y[0] || y[2]*_y[0]!=_y[2]*y[0])
          continue;
        bool flag = true;
        for (int i = 0; i<3; i++)
          if (y[i]!=0 && _y[i]%y[i]!=0) {
            flag = false;
            break;
          }
        if(!flag)
          continue;
        for(int i = 0; i<3; i++)
          out << x[i] << ' ';
        out << _y[0]/y[0] << '\n';
        return 0;
      }
  out << "NONE\n";
  return 0;
}
