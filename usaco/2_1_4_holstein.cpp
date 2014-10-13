/*
PROG: holstein
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

short v, g, ans0 = 520, ans1;
vector<short> V;
vector< vector<short> > G;

bool adequade(vector<short> *s){
	for(short i = 0; i<v; i++)
		if((*s)[i]<V[i])
			return 0;
	return 1;
}

void dfs(short dept, short opti0, short opti1, vector<short> *s){
	if(opti0>=ans0) return;
	if(adequade(s)){
		ans0 = opti0; ans1 = opti1;
		return;
	}
	if(dept==g) return;
	for(short i = 0; i<v; i++)
		(*s)[i] += G[dept][i];
	dfs(dept+1, opti0+1, opti1|(1<<dept), s);
	for(short i = 0; i<v; i++)
		(*s)[i] -= G[dept][i];
	dfs(dept+1, opti0, opti1, s);
}

int main(){
	freopen("holstein.in", "r", stdin);
	cin >> v;
	V.assign(v, 0);
	for(vector<short>::iterator i = V.begin(); i<V.end(); i++)
		cin >> *i;
	cin >> g;
	G.assign(g, vector<short>(v, 0));
	for(vector< vector<short> >::iterator i = G.begin(); i<G.end(); i++)
		for(vector<short>::iterator j = i->begin(); j<i->end(); j++)
			cin >> *j;
	dfs(0, 0, 0, new vector<short>(v, 0));
	freopen("holstein.out", "w", stdout);
	cout << ans0;
	for(short i = 0; i<g; i++)
		if(ans1&(1<<i))
			cout << ' ' << i+1;
	cout << endl;
	return 0;
}
