#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int a=0,b=0,ans=-1;
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
      int c;
      cin>>c;
      if(c>ans){
        ans = c;
        a = i;
        b = j;
      }
    }
  }
  cout<<ans<<'\n'<<a<<' '<<b;
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