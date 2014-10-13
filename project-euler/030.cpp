#include <cstdio>

short path[8];
int ans = 0;

int num(short depth){
	int a = 0;
	for(short i = 0; i<depth; i++)
		a *= 10, a += path[i];
	return a;
}

bool check(short depth){
	int a = num(depth);
	for(short i = 0; i<depth; i++)
		a -= path[i]*path[i]*path[i]*path[i]*path[i];
	return a==0;
}

void dfs(short depth){
	if(depth==7)
		return;
	if(check(depth))
		ans += num(depth);
	for(short i = 0; i<10; i++){
		path[depth] = i;
		dfs(depth+1);
	}
}

int main(){
	for(short i = 1; i<10; i++){
		path[0] = i;
		dfs(1);
	}
	printf("%d", ans-1);
	return 0;
}
