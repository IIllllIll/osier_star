#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int GCD(int a, int b){
  if(a<b) swap(a,b);
  while(b){
    int temp = a%b;
    a = b;
    b = temp;
  }
  return a;
}

int ans[101][101];

void solve(){
  int a,b,w;
  cin>>a>>b>>w;
  int da=0,db=0;
  for(int i=1; i<=a; i++){
    if(a%i!=0) continue;
    for(int j=1; j<=b; j++){
      if(b%j!=0) continue;
      if(i*j*w==a*b){
        da=i;
        db=j;
        break;
      }
    }
  }
  if(da==0&&db==0){
    cout<<"IMPOSSIBLE";
    return;
  }
  int dx=0;
  int dy=0;
  for(int k=0; k<w; k++){
    for(int i=dx; i<dx+da; i++){
      for(int j=dy; j<dy+db; j++)
        ans[i][j] = k;
    }
    dx+=da;
    if(dx==a){
      dx=0;
      dy+=db;
    }
  }
  for(int i=0; i<a; i++){
    for(int j=0; j<b; j++)
      cout<<(char)(ans[i][j]+'A');
    cout<<'\n';
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int ct=1;
  //cin>>ct;
  while(ct--) solve();
  return 0;
}