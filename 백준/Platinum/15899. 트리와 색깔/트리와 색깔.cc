#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> tree[800001];
int arr[200001];
int color[200001];
int s_idx[200001];
int e_idx[200001];
vector<int> v[200001];
int id;

void dfs(int node){
  id++;
  s_idx[node] = id;
  color[id] = arr[node];
  for(int i=0; i<v[node].size(); i++){
    if(s_idx[v[node][i]]==0) dfs(v[node][i]);
  }
  e_idx[node] = id;
}

void update(int node, int s, int e, int idx){
  if(idx<s||idx>e) return;
  tree[node].push_back(color[idx]);
  if(s!=e){
    update(node*2,s,(s+e)/2,idx);
    update(node*2+1,(s+e)/2+1,e,idx);
  }
}

long long Find(int node, int s, int e, int l, int r, long long val){
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) {
    long long cnt = (upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin());
    if(cnt<0) return 0;
    return cnt;
  }
  return Find(node*2,s,(s+e)/2,l,r,val)+Find(node*2+1,(s+e)/2+1,e,l,r,val);
}

void solve(){
  int n,m,c;
  long long ans = 0;
  cin>>n>>m>>c;
  for(int i=1; i<=n; i++)
    cin>>arr[i];
  for(int i=1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  for(int i=1; i<=n; i++) update(1,1,n,i);
  for(int i=0; i<800001; i++) sort(tree[i].begin(),tree[i].end());
  while(m--){
    int a,b;
    cin>>a>>b;
    ans += Find(1,1,n,s_idx[a],e_idx[a],b);
    ans %= 1000000007;
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