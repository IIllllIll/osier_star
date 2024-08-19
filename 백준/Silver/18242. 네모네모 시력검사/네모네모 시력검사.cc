#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int mp[101][101];

void solve(){
  int n,m;
  cin>>n>>m;
  int a,b;
  int dic=0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      char a;
      cin>>a;
      mp[i][j] = a;
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(mp[i][j]=='#') continue;
      if(mp[i-1][j]=='#'&&mp[i+1][j]=='#'){
        dic = 2;
        a=i;
        b=j;
      }
      if(mp[i][j-1]=='#'&&mp[i][j+1]=='#'){
        dic = 1;
        a=i;
        b=j;
      }
    }
  }
  //cout<<dic<<' '<<a<<' '<<b<<'\n';
  if(dic==1){
    int cnt = a;
    while(cnt--){
      if(mp[cnt][b]=='#') {
        cout<<"DOWN";
        return;
      }
    }
    cnt = a;
    while((cnt++)<=n){
      if(mp[cnt][b]=='#') {
        cout<<"UP";
        return;
      }
    }
  }
  else{
    int cnt = b;
    while(cnt--){
      if(mp[a][cnt]=='#'){
        cout<<"RIGHT";
        return;
      }
    }
    cnt = b;
    while((cnt++)<=m){
      if(mp[a][cnt]=='#'){
        cout<<"LEFT";
        return;
      }
    }
    
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