#include<iostream>
#include<string>
using namespace std;

int main(){
  string s, t;
  while(cin>>s>>t){
    string::iterator i = s.begin(), j = t.begin();
    while(i!=s.end()&&j!=t.end()){
      if(*i==*j)
        i++;
      j++;
    }
    cout << (i==s.end() ? "Yes" : "No") << endl;
  }
  return 0;
}
