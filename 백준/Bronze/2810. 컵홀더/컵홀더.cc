#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int check[51];

void solve(){
  int n; cin>>n;
  string a; cin>>a;
  int ans=0;
  for(int i=0; i<n; i++){
    if(a[i]=='S'){
      if(check[i]==0) check[i] = 1;
      else if(check[i+1]==0) check[i+1] = 1;
    }
    else{
      if(check[i]==0) check[i]=1;
      i++;
      if(check[i+1]==0) check[i+1]=1;
    }
  }
  for(int i=0; i<=n; i++)
    ans+=check[i];
  cout<<ans;
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
