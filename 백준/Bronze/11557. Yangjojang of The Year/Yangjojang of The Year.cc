#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int n,mx=0;
  string a;
  cin>>n;
  while(n--){
    int m;
    string b;
    cin>>b>>m;
    if(m>mx){
      mx = m;
      a = b;
    }
  }
  cout<<a<<'\n';
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int ct=1;
  cin>>ct;
  while(ct--) solve();
  return 0;
}