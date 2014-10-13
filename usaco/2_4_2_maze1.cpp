/*
PROG: maze1
USER: danny_c1
LANG: C++
*/
#include <deque>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

ifstream fin("maze1.in");
ofstream fout("maze1.out");

struct coor{
  short x, y;
  inline bool operator < (const coor& other) const{ return x<other.x || (x==other.x&&y<other.y); }
};
short m, n;
char A[201][77];
map<coor, short> B;
deque<coor> C;

int main(){
  fin >> n >> m;
  for(short i = 0; i<(m<<1)+1; i++){
    fin.get();
    for(short j = 0; j<(n<<1)+1; j++)
      A[i][j] = fin.get();
  }
  for(short i = 1; i<(m<<1); i += 2)
    for(short j = 1; j<(n<<1); j += 2){
      B[(coor){i, j}] = 0xfff;
    }
  for(short j = 1; j<(n<<1); j += 2){
    if(A[0][j]==' '){
      B[(coor){1, j}] = 1;
      C.push_back((coor){1, j});
    }
    if(A[m<<1][j]==' '){
      B[(coor){(m<<1)-1,j}] = 1;
      C.push_back((coor){(m<<1)-1, j});
    }
  }
  for(short i = 1; i<(m<<1); i += 2){
    if(A[i][0]==' '){
      B[(coor){i,1}] = 1;
      C.push_back((coor){i, 1});
    }
    if(A[i][n<<1]==' '){
      B[(coor){i,(n<<1)-1}] = 1;
      C.push_back((coor){i, (n<<1)-1});
    }
  }
  const short delt[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while(!C.empty()){
    for(short d = 0; d<4; d++)
      if(C.front().x+delt[d][0]+delt[d][0]>0 && C.front().x+delt[d][0]+delt[d][0]<(m<<1) && C.front().y+delt[d][1]+delt[d][1]>0 && C.front().y+delt[d][1]+delt[d][1]<(n<<1) && A[C.front().x+delt[d][0]][C.front().y+delt[d][1]]==' ' && B[(coor){C.front().x+delt[d][0]+delt[d][0], C.front().y+delt[d][1]+delt[d][1]}]>B[C.front()]+1){
	C.push_back((coor){C.front().x+delt[d][0]+delt[d][0], C.front().y+delt[d][1]+delt[d][1]});
	B[C.back()] = B[C.front()]+1;
      }
      C.pop_front();
  }
  short ans = 0;
  for(short i = 0; i<=(m<<1); i++)
    if(i&1)
      for(short j = 0; j<=(n<<1); j++)
	if(j&1)
          ans = max(ans, B[(coor){i, j}]);
  fout << ans << endl;
  return 0;
}
