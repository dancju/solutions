/*
LANG: C++
PROG: prefix
USER: danny_c1
*/
#include <bitset>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

class node{
public:
	bool exist;
	vector<node*> child;
	void insert(string word){
		if(word=="")
			exist = 1;
		else{
			if(child[word[0]-'A']==0){
				child[word[0]-'A'] = new node;
				(*child[word[0]-'A']).exist = 0;
				child[word[0]-'A']->child.assign(26, static_cast<node*>(0));
			}
			child[word[0]-'A']->insert(word.substr(1, word.size()-1));
		}
	}
} P; //primitives, trie
string S;
bitset<200000> b;
unsigned ans = 0;

void search(unsigned x, node* p){
	if(p->child[S[x]-'A']!=0 && x<S.size())
		search(x+1, p->child[S[x]-'A']);
	if(p->exist && (!b[x])){
		b[x] = 1;
		ans = max(ans, x);
		if(x<=S.size())
			search(x, &P);
	}
}

int main(){
	P.child.assign(26, static_cast<node*>(0));
	string tmp;
	fin >> tmp;
	while(tmp!="."){
		P.insert(tmp);
		fin >> tmp;
	}
	fin >> tmp;
	while(fin.good()){
		S += tmp;
		fin >> tmp;
	}
	search(0, &P);
	fout << ans << endl;
	return 0;
}
