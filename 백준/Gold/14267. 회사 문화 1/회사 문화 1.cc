#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> v[100001];
long long dp[100001];

void dfs(int s, long long val){
  for(int node:v[s]){
    dp[node] += dp[s];
    dfs(node,dp[node]);
  }
}

void solve(){
  int n,m;
  cin>>n>>m;
  int a;
  cin>>a;
  for(int i=2; i<=n; i++){
    cin>>a;
    v[a].push_back(i);
  }
  while(m--){
    int idx,val;
    cin>>idx>>val;
    dp[idx] += val;
  }
  dfs(1,0);
  for(int i=1; i<=n; i++)
    cout<<dp[i]<<' ';
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
