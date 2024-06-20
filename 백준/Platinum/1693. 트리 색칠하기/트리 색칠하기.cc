#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long ans=1e16;
vector<int> v[100001];
long long dp[100001][20];
vector<int> tree[100001];

void make_tree(int node, int pre){
  for(int next : v[node]){
    if(next==pre) continue;
    tree[node].push_back(next);
    make_tree(next,node);
  }
}

long long dfs(int s,int val){
  if(dp[s][val]!=-1) return dp[s][val];
  long long cnt=0;
  for(int node : tree[s]){
    long long mn = 1e16;
    for(int i=1; i<20; i++){
      if(val==i) continue;
      mn = min(mn,dfs(node,i));
    }
    cnt+=mn;
  }
  return dp[s][val] = val+cnt;
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  make_tree(1,0);
  memset(dp,-1,sizeof(dp));
  for(int i=1; i<20; i++)
    ans = min(ans,dfs(1,i));
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