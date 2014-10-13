#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> a;
int n, q, k;
long long ans, _ans = 0;

int main() {
    cin>>n;
    a.resize(n);
    for(vector<long long>::iterator i = a.begin(); i!=a.end(); i++)
        cin>>*i;
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 1; i<n; i++)
        _ans += i*a[i];
    for(vector<long long>::iterator i = a.begin()+1; i!=a.end(); i++)
        *i += *(i-1);
    cin>>q;
    while(q--) {
        cin>>k;
        if(k==1)
            ans = _ans;
        else {
            ans = 0;
            for(long long i = 1, c = 1; i<n; i=i*k+1, c++)
                ans += c*(a[min(i*k, (long long)(n-1))]-a[i-1]);
        }
        cout<<ans<<' ';
    }
    cout<<endl;
    return 0;
}
