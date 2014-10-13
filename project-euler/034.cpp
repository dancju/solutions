#include <iostream>
using namespace std;

int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int sumOfFactorialOfDigits(int x){
    return x==0 ? 0 : sumOfFactorialOfDigits(x/10)+factorial[x%10];
}

int main(){
    int ans = 0;
    for(int i = 10; i<=99999; i++){
	int j = sumOfFactorialOfDigits(i);
	if(i==j) ans += i, cout<<i<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
