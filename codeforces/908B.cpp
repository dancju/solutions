#include<algorithm>
#include<iostream>
using namespace std;

int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int mapping[24][4] = {{0, 1, 2, 3}};
char maze[51][51];
char inst[101];

int main() {
	for(int i = 1; i<24; i++) {
		memcpy(&mapping[i], &mapping[i-1], sizeof(int)*4);
		next_permutation(&(mapping[i][0]), &(mapping[i][4]));
	}
	int l, w, res = 0, xs, ys;
	cin >> l >> w;
	for (int i = 0; i<l; i++)
		scanf("%s", maze[i]);
	scanf("%s", inst);
	for(int i = 0; i<l; i++)
		for(int j = 0; j<w; j++)
			if(maze[i][j]=='S') {
				xs = i;
				ys = j;
			}
	for(int i = 0; i<24; i++) {
		int x = xs, y = ys;
		bool flag = false;
		for(int j = 0; inst[j]!='\0'; j++) {
			x += direction[mapping[i][inst[j]-'0']][0];
			y += direction[mapping[i][inst[j]-'0']][1];
			if(maze[x][y] == 'E') {
				flag = true;
				break;
			} else if (x<0 || x>=l || y<0 || y>=w || maze[x][y]=='#')
				break;
		}
		if(flag)
			res++;
	}
	printf("%d\n", res);
  return 0;
}
