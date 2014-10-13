#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int decimal, ans = 0;
vector<bool> binary;

void check(){
    int backup=decimal;
    binary.clear();
    while(decimal)
	binary.push_back((decimal&1)), decimal>>=1;
    for(int i = 0; i<binary.size()>>1; i++)
	if(binary[i]^binary[binary.size()-i-1])
	    return;
    ans+=backup;
}

vector<short> A(1, 0);
void dfs(){
    int temp = 0;
    for(vector<short>::iterator i = A.begin(); i!=A.end(); i++)
	temp*=10, temp += *i;
    decimal = temp;
    for(vector<short>::reverse_iterator i = A.rbegin(); i!=A.rend(); i++)
	decimal*=10, decimal+=*i;
    check();
    decimal = temp;
    for(vector<short>::reverse_iterator i = A.rbegin()+1; i!=A.rend(); i++)
	decimal*=10, decimal+=*i;
    check();
    if(A.size()<3)
	for(short i = 0; i<10; i++){
	    A.push_back(i);
	    dfs();
	    A.pop_back();
	}
}

int main(){
    for(A.front() = 1; A.front()<10; A.front()++)
	dfs();
    cout<<ans<<endl;
    return 0;
}
