#include<algorithm>
#include<cmath>
#include<iostream>
#include<limits>
#include<vector>
using namespace std;

inline bool equal(const double &a, const double &b){
  return abs(a-b)<numeric_limits<double>::epsilon();
}

inline bool greaterThanOrEqual(const double &a, const double &b){
  return equal(a, b)||(a>b);
}

inline bool lessFirst(const pair<double, double> &a, const pair<double, double> &b){
  return b.first>a.first;
}

int main(){
  int n, l, w;
  while(cin>>n>>l>>w){
    vector< pair<double, double> > s(n);
    int tP, tR;
    for(vector< pair<double, double> >::iterator i = s.begin(); i!=s.end(); i++){
      cin>>tP>>tR;
      if(2*tR>w){
        i->first = tP-sqrt((double)tR*tR-(double)w*w/4);
        i->second = tP+sqrt((double)tR*tR-(double)w*w/4);
      }
      else
        i->first = i->second = INFINITY;
    }
    sort(s.begin(), s.end(), lessFirst);
    while(!s.empty() && s.back().first==INFINITY)
      s.pop_back();
    double t0 = 0, t1 = 0;
    int ans = 1;
    for(vector< pair<double, double> >::iterator i = s.begin(); i!=s.end(); i++)
      if(greaterThanOrEqual(t0, i->first))
        t1 = max(t1, i->second);
      else if(greaterThanOrEqual(t1, i->first)){
        t0 = t1;
        t1 = i->second;
        ans++;
      }
      else
        break;
    cout << (greaterThanOrEqual(t1, l) ? ans : -1) << endl;
  }
  return 0;
}
