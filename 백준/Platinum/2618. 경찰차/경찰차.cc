#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int dp[1001][1001];
int dx[1001];
int dy[1001];
int par[1001][1001];
int m;

int dfs(int a, int b, int idx){
  if(idx==m+1) return 0;
  if(dp[a][b]!=0) return dp[a][b];
  int dist_a = abs(dx[a]-dx[idx])+abs(dy[a]-dy[idx]);
  int dist_b = abs(dx[b]-dx[idx])+abs(dy[b]-dy[idx]);
  int res_a = dist_a+dfs(idx,b,idx+1);
  int res_b = dist_b+dfs(a,idx,idx+1);
  if(res_a<res_b) par[a][b] = 1;
  else par[a][b] = 2;
  return dp[a][b] = min(res_a,res_b);
}

void solve(){
  int n;
  cin>>n>>m;
  for(int i=1; i<=m; i++)
    cin>>dx[i]>>dy[i];
  dx[0] = dy[0] = 1;
  dx[m+1] = dy[m+1] = n;
  cout<<dfs(0,m+1,1)<<'\n';
  int a=0,b=m+1;
  for(int i=1; i<=m; i++){
    cout<<par[a][b]<<'\n';
    if(par[a][b]==1) a = i;
    else b = i;
  }
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
