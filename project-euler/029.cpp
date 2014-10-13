#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

short gcd(short a, short b){
    return b==0 ? a : gcd(b, a%b);
}

const short TOP = 100;
bitset<TOP+1> A;
vector< bitset<TOP+1> > B;
int ans = 0;

int main(){
    for(short I = 2; I<TOP; ){
	while(I<=TOP && A[I])
	    I++;
	if(I>TOP) break;
	short t = 0;
	for(short J = I; J<=TOP; J *= I)
	    A[J] = 1, t++;
	B.assign(t+1, bitset<TOP+1>(0));
	for(short i = 1; i<=t; i++)
	    for(short j = i+1; j<=t; j++)
		for(short k = 0; k<=TOP*i/j; k+=i/gcd(j, i))
		    B[j][k] = 1;
	for(short i = 1; i<=t; i++)
	    ans += B[i].size()-B[i].count()-(B[i][0]==0)-(B[i][1]==0);
    }
    cout<<ans<<endl;
    return 0;
}
