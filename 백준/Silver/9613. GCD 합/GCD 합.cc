#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int GCD(int a, int b){
  if(a>b) swap(a,b);
  int res;
  while(a){
    res = b%a;
    b = a;
    a = res;
  }
  return b;
}

void solve(){
  int n;
  cin>>n;
  long long ans=0;
  vector<int> v;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++)
      ans += GCD(v[i],v[j]);
  }
  cout<<ans<<'\n';
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