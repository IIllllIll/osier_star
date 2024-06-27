#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long dp[100001];
long long ans=0;
long long mod = 1e9+7;
vector<pair<int,int>> v[100001];

long long bfs(int node, int pre){
  long long cnt=1;
  for(pair<int,int> next : v[node]){
    if(next.x==pre) continue;
    long long val = (bfs(next.x,node)*next.y)%mod;
    ans = (((val*cnt)%mod)+ans)%mod;
    cnt = (cnt+val)%mod;
  }
  return cnt;
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<n; i++){
    int a,b,w;
    cin>>a>>b>>w;
    v[a].push_back({b,w});
    v[b].push_back({a,w});
  }
  bfs(1,1);
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
