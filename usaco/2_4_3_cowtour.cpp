/*
PROG: cowtour
LANG: C++
USER: danny_c1
*/
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

short n;
struct coor{ int x, y; } A[160];
double B[150][150];
vector<double> C;

inline double dis(short i, short j){
  return sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+(A[i].y-A[j].y)*(A[i].y-A[j].y));
}

int main(){
  fin >> n;
  for(coor* i = A; i<A+n; i++)
    fin >> i->x >> i->y;
  for(short i = 0; i<n; i++)
    for(short j = 0; j<n; j++){
      char tmp;
      fin >> tmp;
      if(tmp=='1')
        B[i][j] = dis(i, j);
      else if(i==j)
        B[i][j] = 0;
      else
        B[i][j] = INFINITY;
    }
  for(short k = 0; k<n; k++)
    for(short i = 0; i<n; i++)
      if(B[i][k]!=INFINITY)
        for(short j = 0; j<n; j++)
          B[i][j] = min(B[i][j], B[i][k]+B[k][j]);
  C.assign(n, 0);
  for(short i = 0; i<n; i++)
    for(short j = 0; j<n; j++)
      if(B[i][j]!=INFINITY)
        C[i] = max(C[i], B[i][j]);
  double ans = INFINITY;
  for(short i = 0; i<n; i++)
    for(short j = 0; j<n; j++)
      if(B[i][j]==INFINITY)
        ans = min(ans, C[i]+C[j]+dis(i, j));
  for(short i = 0; i<n; i++)
    ans = max(ans, C[i]);
  fout << setprecision(6) << setiosflags(ios::fixed | ios::showpoint) << ans << endl;
  return 0;
}
