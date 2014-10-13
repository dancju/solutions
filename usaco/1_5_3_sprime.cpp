/*
PROG: sprime
USER: danny_c1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool prime(int x){
	for(int i = 2; i*i<=x; i++)
		if(x%i==0)
			return 0;
	return 1;
}

vector< vector<int> > a;

int main(){
	short n;
	freopen("sprime.in", "r", stdin);
	cin >> n;
	a.assign(1, vector<int>());
	a.front().push_back(2);
	a.front().push_back(3);
	a.front().push_back(5);
	a.front().push_back(7);
	while(--n){
		a.push_back(vector<int>());
		for(vector<int>::iterator j = (a.end()-2)->begin(); j<(a.end()-2)->end(); j++){
			if(prime(*j*10+1)) a.back().push_back(*j*10+1);
			if(prime(*j*10+3)) a.back().push_back(*j*10+3);
			if(prime(*j*10+7)) a.back().push_back(*j*10+7);
			if(prime(*j*10+9)) a.back().push_back(*j*10+9);
		}
	}
	freopen("sprime.out", "w", stdout);
	for(vector<int>::iterator j = a.back().begin(); j<a.back().end(); j++)cout << *j << endl;
	return 0;
}
