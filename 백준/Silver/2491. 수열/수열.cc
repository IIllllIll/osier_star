#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int up_dp[100001];
int down_dp[100001];
int arr[100001];

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i=1; i<=n; i++){
    if(arr[i-1]>arr[i]){
      up_dp[i] = 1;
      continue;
    } 
    up_dp[i] = up_dp[i-1]+1;
  }
  for(int i=1; i<=n; i++){
    if(arr[i-1]<arr[i]) {
      down_dp[i] = 1;
      continue;
    }
    down_dp[i] = down_dp[i-1]+1;
  }

  int ans=0;
  for(int i=1; i<=n; i++)
    ans = max(ans,max(up_dp[i],down_dp[i]));
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
