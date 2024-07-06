#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long mod = 1000000000;
long long dp[101][10][1<<10];

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<10; i++)
    dp[1][i][1<<i] = 1;
  for(int i=2; i<=n; i++){
    for(int j=0; j<10; j++){
      for(int k=0; k<1024; k++){
        if(j>0)
          dp[i][j][k|(1<<j)] += dp[i-1][j-1][k];
        if(j<9)
          dp[i][j][k|(1<<j)] += dp[i-1][j+1][k];
        dp[i][j][k|(1<<j)]%=mod;
      }
    }
  }
  long long ans=0;
  for(int i=0; i<10; i++){
    ans = (ans+dp[n][i][1023])%mod;
  }
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
