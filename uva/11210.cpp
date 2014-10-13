#include<cstdio>
#include<cstring>

const char* id2name[] = {
  "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
  "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
  "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
  "DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"};

int name2id(const char* name){
  for(int i = 0; 1; i++)
    if(strcmp(name, id2name[i])==0)
      return i;
}

int nId[34];

bool huT(){
  int i = 0;
  for(; nId[i]==0 && i<9; i++);
  if(i==9) return 1;
  if(nId[i]>=3){
    nId[i] -= 3;
    if(huT()){
      nId[i] += 3;
      return 1;
    }
    nId[i] += 3;
  }
  if(i+2<9 && nId[i] && nId[i+1] && nId[i+2]){
    nId[i]--; nId[i+1]--; nId[i+2]--;
    if(huT()){
      nId[i]++; nId[i+1]++; nId[i+2]++;
      return 1;
    }
    nId[i]++; nId[i+1]++; nId[i+2]++;
  }
  return 0;
}

bool huS(){
  int i = 9;
  for(; nId[i]==0 && i<18; i++);
  if(i==18) return 1;
  if(nId[i]>=3){
    nId[i] -= 3;
    if(huS()){
      nId[i] += 3;
      return 1;
    }
    nId[i] += 3;
  }
  if(i+2<18 && nId[i] && nId[i+1] && nId[i+2]){
    nId[i]--; nId[i+1]--; nId[i+2]--;
    if(huS()){
      nId[i]++; nId[i+1]++; nId[i+2]++;
      return 1;
    }
    nId[i]++; nId[i+1]++; nId[i+2]++;
  }
  return 0;
}

bool huW(){
  int i = 18;
  for(; nId[i]==0 && i<27; i++);
  if(i==27) return 1;
  if(nId[i]>=3){
    nId[i] -= 3;
    if(huW()){
      nId[i] += 3;
      return 1;
    }
    nId[i] += 3;
  }
  if(i+2<27 && nId[i] && nId[i+1] && nId[i+2]){
    nId[i]--; nId[i+1]--; nId[i+2]--;
    if(huW()){
      nId[i]++; nId[i+1]++; nId[i+2]++;
      return 1;
    }
    nId[i]++; nId[i+1]++; nId[i+2]++;
  }
  return 0;
}

bool huC(){
  int i = 27;
  for(; nId[i]==0 && i<34; i++);
  if(i==34) return 1;
  if(nId[i]>=3){
    nId[i] -= 3;
    if(huC()){
      nId[i] += 3;
      return 1;
    }
    nId[i] += 3;
  }
  return 0;
}

bool hu(){
  bool jiang = 0;
  if(!huT()){
    for(int i = 0; i<9; i++)
      if(nId[i]>=2){
        nId[i] -= 2;
        if(huT()){
          jiang = 1;
          nId[i] += 2;
          break;
        }
        nId[i] += 2;
      }
    if(!jiang) return 0;
  }
  if(!huS()){
    if(jiang) return 0;
    for(int i = 9; i<18; i++)
      if(nId[i]>=2){
        nId[i] -= 2;
        if(huS()){
          jiang = 1;
          nId[i] += 2;
          break;
        }
        nId[i] += 2;
      }
    if(!jiang) return 0;
  }
  if(!huW()){
    if(jiang) return 0;
    for(int i = 18; i<27; i++)
      if(nId[i]>=2){
        nId[i] -= 2;
        if(huW()){
          jiang = 1;
          nId[i] += 2;
          break;
        }
        nId[i] += 2;
      }
    if(!jiang) return 0;
  }
  if(!huC()){
    if(jiang) return 0;
    for(int i = 27; i<34; i++)
      if(nId[i]>=2){
        nId[i] -= 2;
        if(huC()){
          jiang = 1;
          nId[i] += 2;
          break;
        }
        nId[i] += 2;
      }
    if(!jiang) return 0;
  }
  return 1;
}

int main(){
  int cCase = 0;
  char name[5];
  while(scanf("%s", name), name[0]!='0'){
    printf("Case %d:", ++cCase);
    memset(nId, 0, sizeof(nId));
    nId[name2id(name)]++;
    for(int i = 1; i<13; i++){
      scanf("%s", name);
      nId[name2id(name)]++;
    }
    bool ready = 0;
    for(int i = 0; i<34; i++)
      if((nId[i] || (i-1 && nId[i-1]) || (i+1<34 && nId[i+1]))&&nId[i]<4){
        nId[i]++;
        if(hu()){
          printf(" %s", id2name[i]);
          ready = 1;
        }
        nId[i]--;
      }
    if(!ready) printf(" Not ready");
    printf("\n");
  }
  return 0;
}
