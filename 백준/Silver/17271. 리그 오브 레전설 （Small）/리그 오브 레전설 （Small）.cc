#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long dp[10001];
long long mod = 1e9+7;

void solve(){
  long long n,m;
  cin>>n>>m;
  for(int i=1; i<m; i++) dp[i] = 1;
  dp[m] = 2;
  for(int i=m+1; i<=n; i++){
    dp[i] = (dp[i-1]+dp[i-m])%mod;
  }
  cout<<dp[n];
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