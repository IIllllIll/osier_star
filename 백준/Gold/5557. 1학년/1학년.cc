#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long dp[21];
long long arr[101];

void solve(){
  int n,ans;
  cin>>n;
  for(int i=0; i<n-1; i++) cin>>arr[i];
  cin>>ans;
  dp[arr[0]]++;
  for(int i=1; i<n-1; i++){
    long long tmp[21];
    memset(tmp,0,sizeof(tmp));
    for(int j=0; j<=20; j++){
      if(dp[j]==0) continue;
      int next = j;
      if(next+arr[i]>=0&&next+arr[i]<=20) tmp[next+arr[i]] += dp[j];
      if(next-arr[i]>=0&&next-arr[i]<=20) tmp[next-arr[i]] += dp[j];
    }
    for(int j=0; j<=20; j++) 
      dp[j] = tmp[j];
  }
  cout<<dp[ans];
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