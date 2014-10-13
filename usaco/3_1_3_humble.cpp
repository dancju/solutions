/*
ID: danny_c1
PROG: humble
LANG: C++
*/
#include <fstream>
#include <list>
#include <vector>
using namespace std;

unsigned n, k;
struct Item{
	unsigned prime;
	list<unsigned>::iterator pointer;
};
vector<Item> A;
list<unsigned> B;

int main(){
	ifstream fin("humble.in");
	fin >> k >> n;
	B.assign(1, 1);
	A.assign(k, Item{0, B.begin()});
	for(vector<Item>::iterator i = A.begin(); i!=A.end(); i++)
		fin >> i->prime;
	while(n--){
		unsigned min = 0x7fffffff;
		vector<Item>::iterator mark;
		for(vector<Item>::iterator i = A.begin(); i!=A.end(); i++){
			if(B.back()==(i->prime)*(*(i->pointer)))
				i->pointer++;
			if(min>(i->prime)*(*(i->pointer))){
				min = (i->prime)*(*(i->pointer));
				mark = i;
			}
		}
		B.push_back(min);
		mark->pointer++;
	}
	ofstream fout("humble.out");
	fout << B.back() << endl;
	return 0;
}
