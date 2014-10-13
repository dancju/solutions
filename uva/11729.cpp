#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Job{
  public:
    int j, b;
    inline bool operator<(const Job& other)const{
      return j>other.j;
    }
};

int main(){
  int n, t = 0;
  while(cin>>n, n){
    vector<Job> soldior(n);
    for(vector<Job>::iterator i = soldior.begin(); i!=soldior.end(); i++)
      cin>>i->b>>i->j;
    sort(soldior.begin(), soldior.end());
    int ans = soldior.front().b+soldior.front().j;
    for(vector<Job>::iterator i = soldior.begin()+1; i!=soldior.end(); i++){
      i->b += (i-1)->b;
      ans = max(ans, i->b+i->j);
    }
    cout<<"Case "<<++t<<": "<<ans<<endl;
  }
  return 0;
}
