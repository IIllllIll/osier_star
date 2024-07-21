#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define X first
#define Y second

int visited[1001][1001];
char mp[1001][1001];
int n,m,ans;

void dfs(int a, int b, int k){
  if(visited[a][b]){
    if(visited[a][b]==k)
      ans++;
    return;
  }
  visited[a][b] = k;
  if(mp[a][b]=='D') a++;
  else if(mp[a][b]=='U') a--;
  else if(mp[a][b]=='R') b++;
  else b--;
  dfs(a,b,k);
}

void solve(){
  int cnt=1;
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cin>>mp[i][j];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(visited[i][j]) continue;
      dfs(i,j,cnt);
      cnt++;
    }
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