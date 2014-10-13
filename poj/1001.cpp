#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class UnsignedFloat{
  int exponent;
  deque<short> decimal;
  public:
  UnsignedFloat(){
    exponent = 0;
    decimal.clear();
  }
  UnsignedFloat operator = (string x){
    if(x.find('.')==string::npos)
      exponent = 0;
    else{
      exponent = x.size()-x.find('.')-1;
      x.erase(x.find('.'), 1);
    }
    decimal.clear();
    while(!x.empty()){
      decimal.push_back(x[x.size()-1]-'0');
      x.erase(x.end()-1);
    }
    while(decimal.front()==0){
      decimal.pop_front();
      exponent--;
    }
    while(decimal.back()==0)
      decimal.pop_back();
    return *this;
  }
  string toString() const {
    string ans = "";
    if(exponent>=(int)decimal.size()){
      cout << ".";
      for(int i = 0; i!=exponent-decimal.size(); i++) cout << 0;
    }
    for(int i = decimal.size()-1; i!=-1; i--){
      cout << decimal[i];
      if(i==exponent && i!=0) cout << '.';
    }
    for(int i = exponent; i<0; i++) cout << 0;
    return ans;
  }
  UnsignedFloat operator * (const UnsignedFloat & other) const {
    UnsignedFloat ans;
    ans.exponent = exponent + other.exponent;
    ans.decimal.assign(decimal.size()+other.decimal.size(), 0);
    for(int i = 0; i<decimal.size(); i++)
      for(int j = 0; j<other.decimal.size(); j++)
        ans.decimal[i+j] += decimal[i]*other.decimal[j];
    for(deque<short>::iterator i = ans.decimal.begin(); i!=ans.decimal.end()-1; i++){
      *(i+1) += *i/10;
      *i %= 10;
    }
    while(ans.decimal.back()==0) ans.decimal.pop_back();
    return ans;
  }
} A, B;

istream & operator >> (istream & in, UnsignedFloat & x){
  string s;
  in >> s;
  if(s!="")
    x = s;
  return in;
}

ostream & operator << (ostream & out, UnsignedFloat & x){
  out << x.toString();
  return out;
}

int main(){
  short n;
  while(cin >> A >> n){
    B = "1";
    while(n--) B = A*B;
    cout << B << endl;
  }
  return 0;
}
