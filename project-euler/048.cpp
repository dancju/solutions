#include <deque>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Integer{
  deque<short> decimal;
public:
  Integer(){
    decimal.clear();
  }
  Integer operator = (long x){
    decimal.clear();
    while(x!=0){
      decimal.push_back(x%10);
      x /= 10;
    }
    return *this;
  }
  Integer operator = (string x){
    decimal.clear();
    while(!x.empty()){
      decimal.push_back(x[x.size()-1]-'0');
      x.erase(x.end()-1);
    }
    return *this;
  }
  Integer(const long x){ *this = x; }
  Integer(const string x){ *this = x; }
  string toString(){
    if(decimal.empty()) return "0";
    string ans = "";
    for(deque<short>::reverse_iterator i = decimal.rbegin(); i!=decimal.rend(); i++)
      ans.insert(ans.end(), '0'+(*i));
    return ans;
  }
  Integer operator + (const Integer & other) const {
    Integer ans;
    ans.decimal.assign(max(decimal.size(), other.decimal.size()), 0);
    for(int i = 0; i<ans.decimal.size(); i++){
      if(i<decimal.size()) ans.decimal[i] += decimal[i];
      if(i<other.decimal.size()) ans.decimal[i] += other.decimal[i];
      if(i){
	ans.decimal[i] += ans.decimal[i-1]/10;
	ans.decimal[i-1] %= 10;
      }
    }
    if(ans.decimal.back()>9){
      ans.decimal.push_back(ans.decimal.back()/10);
      *(ans.decimal.end()-2) %= 10;
    }
    return ans; 
  }
  Integer operator += (const Integer & other){
    *this = *this + other;
    return *this;
  }
  Integer operator * (const Integer & other) const {
    Integer ans;
    ans.decimal.assign(decimal.size()+other.decimal.size(), 0);
    for(int i = 0; i<decimal.size(); i++)
      for(int j = 0; j<other.decimal.size(); j++)
        ans.decimal[i+j] += decimal[i]*other.decimal[j];
    for(deque<short>::iterator i = ans.decimal.begin(); i!=ans.decimal.end()-1; i++){
      *(i+1) += (*i)/10;
      *i %= 10;
    }
    while(!ans.decimal.empty() && ans.decimal.back()==0) ans.decimal.pop_back();
    return ans;
  }
  Integer operator*= (const Integer & other){
    *this = *this * other;
    return *this;
  }
  void cut(const int & x){
    while(decimal.size()>x)
      decimal.pop_back();
  }
} A, B;

ostream& operator << (ostream & out, Integer & x){
  out << x.toString();
  return out;
}

int main(){
  A = 0;
  for(short i = 1; i<=1000; i++){
    B = 1;
    for(short j = 0; j<i; j++){
      B *= i;
      B.cut(10);
    }
    A += B;
    A.cut(10);
  }
  cout<<A<<endl;
  return 0;
}
