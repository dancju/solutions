/*
PROG: hamming
USER: danny_c1
LANG: C++
*/
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

short dist(short a, short b){
	a ^= b;
	a = (a&0x55)+((a&0xAA)>>1);
	a = (a&0x33)+((a&0xCC)>>2);
	a = (a&0x0F)+((a&0xF0)>>4);
	return a;
}

short n, b, d;
vector<short> path;
bool match(short x){
	for(vector<short>::iterator i = path.begin(); i<path.end(); i++)
		if(dist(*i, x)<d)
			return 0;
	return 1;
}
void search(){
	if(path.size()==n){
		freopen("hamming.out", "w", stdout);
		for(vector<short>::iterator i = path.begin(); i<path.end(); i++){
			cout << *i;
			if((i-path.begin())%10==9)
				cout << endl;
			else if(i!=path.end()-1)
				cout << ' ';
		}
		if(n%10!=0)
			cout << endl;
		exit(0);
	}
	for(short i = path.back()+1; i<b; i++)
		if(match(i)){
			path.push_back(i);
			search();
			path.pop_back();
		}
}

int main(){
	freopen("hamming.in", "r", stdin);
	cin >> n >> b >> d;
	b = 1<<b;
	path.push_back(0);
	search();
	return 0;
}
