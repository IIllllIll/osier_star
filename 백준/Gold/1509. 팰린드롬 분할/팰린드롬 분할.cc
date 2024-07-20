#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define X first
#define Y second

bool check[2501][2501];
int dp[2501];
string a;
int n;

void solve(){
  cin>>a;
  n = a.size();
  for(int i=0; i<n; i++){
    for(int j=i; j>=0; j--){
      if(a[i]!=a[j]) continue;
      if(i-j<2) check[j][i] = 1;
      else check[j][i] = check[j+1][i-1];
    }
  }
  dp[0] = 0;
  for(int i=1; i<=n; i++) dp[i] = 1e8;
  for(int i=1; i<=n; i++){
    for(int j=i; j>=1; j--){
      int s = j-1, e = i-1;
      if(check[s][e]) dp[i] = min(dp[i],dp[j-1]+1);
    }
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