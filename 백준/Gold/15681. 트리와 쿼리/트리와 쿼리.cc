#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> v[200001];
int ans[200001];
bool visited[200001];

void dfs(int s){
  visited[s] = true;
  for(int i : v[s]){
    if(!visited[i]){
      dfs(i);
      ans[s]+=ans[i];
    }
  }
  ans[s]++;
  //cout<<ans[s]<<' '<<s<<'\n';
  return;
}

void solve(){
  int n,r,q;
  cin>>n>>r>>q;
  for(int i=0; i<n-1; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(r);
  while(q--){
    int a;
    cin>>a;
    cout<<ans[a]<<'\n';
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
