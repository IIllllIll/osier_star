#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second



void solve(){
  int n;
  long long a=0,b=0;
  cin>>n;
  while(n--){
    long long c,d;
    cin>>c>>d;
    a+=c;
    b+=d;
    cout<<a-b<<'\n';
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
