#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int n,m;
int mp[21][21];
bool check[27];
int ans=0;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void dfs(int a, int b, int cnt){
  ans = max(ans,cnt);
  for(int i=0; i<4; i++){
    int na = a+dx[i];
    int nb = b+dy[i];
    if(na<0||na>=n||nb<0||nb>=m) continue;
    if(check[mp[na][nb]]) continue;
    check[mp[na][nb]] = true;
    dfs(na,nb,cnt+1);
    check[mp[na][nb]] = false;
  }
}

void solve(){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    string a;
    cin>>a;
    for(int j=0; j<m;j++)
      mp[i][j] = a[j]-'A';
  }
  check[mp[0][0]] = true;
  dfs(0,0,1);
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