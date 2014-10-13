/*
PROG: pprime
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

vector<int> a;

int main(){
	a.push_back(5); a.push_back(7); a.push_back(11);
	for(short b0 = 1; b0<10; b0 += 2)
		for(short b1 = 0; b1<10; b1++){
			short tmp = b0+b1*10+b0*100;
			if(prime(tmp)) a.push_back(tmp);
		}
	for(short b0 = 1; b0<10; b0 += 2)
		for(short b1 = 0; b1<10; b1++)
			for(short b2 = 0; b2<10; b2++){
					int tmp = b0+b1*10+b2*100+b1*1000+b0*10000;
					if(prime(tmp)) a.push_back(tmp);
				}
	for(short b0 = 1; b0<10; b0 += 2)
		for(short b1 = 0; b1<10; b1++)
			for(short b2 = 0; b2<10; b2++)
				for(short b3 = 0; b3<10; b3++){
					int tmp = b0+b1*10+b2*100+b3*1000+b2*10000+b1*100000+b0*1000000;
					if(prime(tmp)) a.push_back(tmp);
				}
	a.push_back(100000001);
	int f, b;
	freopen("pprime.in", "r", stdin);
	cin >> f >> b;
	vector<int>::iterator i = a.begin();
	while(*i<f) i++;
	freopen("pprime.out", "w", stdout);
	for(;*i<=b; i++) cout << *i << endl;
	return 0;
}
