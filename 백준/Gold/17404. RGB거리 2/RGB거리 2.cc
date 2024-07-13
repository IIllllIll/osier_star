#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long inf = 1e10;
long long arr[1001][3];
long long dp[1001][3];

void init(int n){
  for(int i=1; i<=n; i++){
    dp[i][0] = inf;
    dp[i][1] = inf;
    dp[i][2] = inf;
  }
}

void solve(){
  int n;
  long long ans = inf;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  init(n);
  dp[1][0] = arr[1][0];
  for(int i=2; i<=n; i++){
    dp[i][0] = min(dp[i-1][1],dp[i-1][2])+arr[i][0];
    dp[i][1] = min(dp[i-1][0],dp[i-1][2])+arr[i][1];
    dp[i][2] = min(dp[i-1][0],dp[i-1][1])+arr[i][2];
  }
  ans = min(ans,min(dp[n][1],dp[n][2]));
  init(n);
  dp[1][1] = arr[1][1];
  for(int i=2; i<=n; i++){
    dp[i][0] = min(dp[i-1][1],dp[i-1][2])+arr[i][0];
    dp[i][1] = min(dp[i-1][0],dp[i-1][2])+arr[i][1];
    dp[i][2] = min(dp[i-1][0],dp[i-1][1])+arr[i][2];
  }
  ans = min(ans,min(dp[n][0],dp[n][2]));
  init(n);
  dp[1][2] = arr[1][2];
  for(int i=2; i<=n; i++){
    dp[i][0] = min(dp[i-1][1],dp[i-1][2])+arr[i][0];
    dp[i][1] = min(dp[i-1][0],dp[i-1][2])+arr[i][1];
    dp[i][2] = min(dp[i-1][0],dp[i-1][1])+arr[i][2];
  }
  ans = min(ans,min(dp[n][1],dp[n][0]));
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