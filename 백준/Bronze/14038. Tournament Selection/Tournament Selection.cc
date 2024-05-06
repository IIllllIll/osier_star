#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int a=0;
  for(int i=0; i<6; i++){
    char b;
    cin>>b;
    if(b=='W') a++;
  }
  if(a==5|a==6) cout<<1;
  else if(a==4||a==3) cout<<2;
  else if(a==2||a==1) cout<<3;
  else cout<<-1;
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