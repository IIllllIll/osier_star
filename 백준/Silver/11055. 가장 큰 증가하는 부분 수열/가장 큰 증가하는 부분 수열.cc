#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[1001];
int dp[1001];

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<=n; i++){
    int mx=0;
    for(int j=0; j<i; j++){
      if(arr[i]<=arr[j]) continue;
      mx = max(mx,dp[j]);
    }
    dp[i] = mx+arr[i];
  }
  int ans=0;
  for(int i=1; i<=n; i++)
    ans = max(ans,dp[i]);
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
