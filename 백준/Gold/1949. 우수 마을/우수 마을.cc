#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> v[10001];
int cost[10001];
int dp[10001][2];
bool visited[100001];

void dfs(int s){
  visited[s] = true;
  dp[s][1] = cost[s];
  for(int i:v[s]){
    if(!visited[i]){
      dfs(i);
      dp[s][0] += max(dp[i][0],dp[i][1]);
      dp[s][1] += dp[i][0];
    }
  }
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>cost[i];
  for(int i=1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  cout<<max(dp[1][0],dp[1][1]);
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
