#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Before{
  int id, coordinate;
  inline bool operator<(const Before & other)const{
    return coordinate<other.coordinate;
  }
};

struct After{
  int id, coordinate;
  string direction;
};

inline bool sbc(const After&a, const After&b){
  return a.coordinate<b.coordinate;
}

inline bool sbi(const After&a, const After&b){
  return a.id<b.id;
}

int main(){
  int nCase;
  cin>>nCase;
  for(int _case = 1; _case<=nCase; _case++){
    cout<<"Case #"<<_case<<':'<<endl;
    int l, t, n;
    cin>>l>>t>>n;
    vector<Before> before(n);
    vector<After> after(n);
    for(int i = 0; i<n; i++){
      before[i].id  = i;
      cin>>before[i].coordinate>>after[i].direction;
      if(after[i].direction=="R")
        after[i].coordinate = before[i].coordinate+t;
      else
        after[i].coordinate = before[i].coordinate-t;
    }
    sort(before.begin(), before.end());
    sort(after.begin(), after.end(), sbc);
    for(int i = 0; i<n; i++){
      after[i].id = before[i].id;
      if(i && after[i].coordinate==after[i-1].coordinate)
        after[i-1].direction = after[i].direction = "Turning";
    }
    sort(after.begin(), after.end(), sbi);
    for(vector<After>::iterator i = after.begin(); i!=after.end(); i++){
      if(i->coordinate>=0 && i->coordinate<=l)
        cout<<(i->coordinate)<<' '<<(i->direction)<<endl;
      else cout<<"Fell off"<<endl;
    }
    cout<<endl;
  }
  return 0;
}
