/*
PROG: ttwo
USER: danny_c1
LANG: C++
*/
#include <fstream>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char A[10][10];
short delt[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool book[4][10][10][4][10][10];

int main(){
	short Cx, Cy, Fx, Fy;
	for(short i = 0; i<10; i++)
		for(short j = 0; j<10; j++){
			fin >> A[i][j];
			if(A[i][j]=='C')
				Cx = i, Cy = j, A[i][j] = '.';
			else if(A[i][j]=='F')
				Fx = i, Fy = j, A[i][j] = '.';
		}
	for(short ans = 0, Cd = 0, Fd = 0; 1; ans++){
		if(book[Cd][Cx][Cy][Fd][Fx][Fy]){
			fout << 0 << endl;
			return 0;
		}
		if(Cx==Fx && Cy==Fy){
			fout << ans << endl;
			return 0;
		}
		book[Cd][Cx][Cy][Fd][Fx][Fy] = 1;
		if(Cx+delt[Cd][0]==-1 || Cx+delt[Cd][0]==10 || Cy+delt[Cd][1]==-1 || Cy+delt[Cd][1]==10 || A[Cx+delt[Cd][0]][Cy+delt[Cd][1]]=='*')
			Cd++, Cd %= 4;
		else
			Cx += delt[Cd][0], Cy += delt[Cd][1];
		if(Fx+delt[Fd][0]==-1 || Fx+delt[Fd][0]==10 || Fy+delt[Fd][1]==-1 || Fy+delt[Fd][1]==10 || A[Fx+delt[Fd][0]][Fy+delt[Fd][1]]=='*')
			Fd++, Fd %= 4;
		else
			Fx += delt[Fd][0], Fy += delt[Fd][1];
	}
}
