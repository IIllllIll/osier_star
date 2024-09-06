#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void f(int n, int cnt, bool check){
  if(n==3){
    if(cnt==1){
      cout<<"  *";
    }
    else if(cnt==2){
      cout<<" * *";
    }
    else cout<<"*****";
    if(check) cout<<'\n';
    return;
  }
  if(cnt<=n/2){
    for(int i=0; i<n/2; i++)
      cout<<' ';
    f(n/2,cnt,check);
  }
  else{
    cnt-=n/2;
    f(n/2,cnt,false);
    for(int i=0; i<(n/2)-cnt+1; i++)
      cout<<' ';
    f(n/2,cnt,check);
  }
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    f(n,i,false);
    for(int j=0; j<n-i; j++) cout<<' ';
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