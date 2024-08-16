#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int a,b,c;
  cin>>a>>b>>c;
  if(b<c) swap(b,c);
  if(a<b) swap(b,a);
  if(a==b&&b==c&&a==c)
    cout<<2;
  else if(a*a==b*b+c*c)
    cout<<1;
  else
    cout<<0;
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