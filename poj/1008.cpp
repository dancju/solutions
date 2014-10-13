#include <iostream>
#include <map>
#include <string>
using namespace std;

string Tzolkin[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
map<string, short> Haab;

int string2int(string x){
  int ans = 0;
  for(string::iterator i = x.begin(); i!=x.end(); i++)
    ans *= 10, ans += *i, ans -= '0';
  return ans;
}

int main(){
  Haab["pop"]=0;
  Haab["no"]=1;
  Haab["zip"]=2;
  Haab["zotz"]=3;
  Haab["tzec"]=4;
  Haab["xul"]=5;
  Haab["yoxkin"]=6;
  Haab["mol"]=7;
  Haab["chen"]=8;
  Haab["yax"]=9;
  Haab["zac"]=10;
  Haab["ceh"]=11;
  Haab["mac"]=12;
  Haab["kankin"]=13;
  Haab["muan"]=14;
  Haab["pax"]=15;
  Haab["koyab"]=16;
  Haab["cumhu"]=17;
  Haab["uayet"]=18;
  string _d, m;
  short y, d;
  int n, D;
  cin>>n;
  cout<<n<<endl;
  while(cin>>_d>>m>>y){
    d = string2int(_d.substr(0, _d.size()-1));
    D = y*365+Haab[m]*20+d;
    cout<<D%13+1<<' '<<Tzolkin[D%20]<<' '<<D/260<<endl;
  }
  return 0;
}
