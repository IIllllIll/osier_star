#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[201];
long long dp[201][201];
long long inf = 1e10;

void solve(){
  int n,k;
  cin>>n>>k;
  int idx=1;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    if(a!=arr[idx-1]){
      arr[idx] = a;
      idx++;
    }
  }
  n = idx-1;
  
  long long ans = inf;
  for(int i=1; i<n; i++){
    for(int s=1; s<=n-i; s++){
      int e = s+i;
      long long temp = inf;
      int cnt = arr[s]==arr[e]?0:1;
      for(int j=s; j<e; j++)
        temp = min(temp,dp[s][j]+dp[j+1][e]+cnt);
      dp[s][e] = temp;
    }
  }
  for(int i=1; i<=k; i++)
    ans = min(ans,dp[1][n]);
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
