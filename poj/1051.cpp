#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, char> decode;
map<char, string> encode;

int main(){
  encode['A']=".-";	decode[".-"]='A';
  encode['B']="-...";	decode["-..."]='B';
  encode['C']="-.-.";	decode["-.-."]='C';
  encode['D']="-..";	decode["-.."]='D';
  encode['E']=".";	decode["."]='E';
  encode['F']="..-.";	decode["..-."]='F';
  encode['G']="--.";	decode["--."]='G';
  encode['H']="....";	decode["...."]='H';
  encode['I']="..";	decode[".."]='I';
  encode['J']=".---";	decode[".---"]='J';
  encode['K']="-.-";	decode["-.-"]='K';
  encode['L']=".-..";	decode[".-.."]='L';
  encode['M']="--";	decode["--"]='M';
  encode['N']="-.";	decode["-."]='N';
  encode['O']="---";	decode["---"]='O';
  encode['P']=".--.";	decode[".--."]='P';
  encode['Q']="--.-";	decode["--.-"]='Q';
  encode['R']=".-.";	decode[".-."]='R';
  encode['S']="...";	decode["..."]='S';
  encode['T']="-";	decode["-"]='T';
  encode['U']="..-";	decode["..-"]='U';
  encode['V']="...-";	decode["...-"]='V';
  encode['W']=".--";	decode[".--"]='W';
  encode['X']="-..-";	decode["-..-"]='X';
  encode['Y']="-.--";	decode["-.--"]='Y';
  encode['Z']="--..";	decode["--.."]='Z';
  encode['_']="..--";	decode["..--"]='_';
  encode[',']=".-.-";	decode[".-.-"]=',';
  encode['.']="---.";	decode["---."]='.';
  encode['?']="----";	decode["----"]='?';
  int n;
  string cipher, plain, morse;
  cin>>n;
  for(int k = 1; k<=n; k++){
    cin>>cipher;
    morse="";
    for(string::iterator i=cipher.begin(); i<cipher.end();i++)
      morse+=encode[*i];
    short j=0;
    cout<<k<<": ";
    for(string::reverse_iterator i=cipher.rbegin(); i!=cipher.rend(); i++){
      cout<<decode[morse.substr(j, encode[*i].size())];
      j+=encode[*i].size();
    }
    cout<<endl;
  }
}
