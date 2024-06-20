#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int height[200001];
int st[200001];
int ed[200001];
vector<int> v[200001];
int cnt=0;
int tree[800001];

void update(int node, int s, int e, int idx, long long val){
  if(idx>e||idx<s) return;
  if(s==e) {
    tree[node] += val;
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  tree[node] = tree[node*2]+tree[node*2+1];
} 

long long Find(int node, int s, int e, int l,int r){
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) return tree[node];
  return Find(node*2,s,(s+e)/2,l,r)+Find(node*2+1,(s+e)/2+1,e,l,r);
}

void dfs(int s, int h){
  cnt++;
  st[s] = cnt;
  height[s] = h;
  for(int node : v[s]){
    if(st[node]==0)
      dfs(node,h+1);
  }
  ed[s] = cnt;
}

void solve(){
  int n,k;
  cin>>n>>k;
  for(int i=1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(k,1);
  int m;
  cin>>m;
  while(m--){
    int a,b;
    cin>>a>>b;
    if(a==1){
      update(1,1,n,st[b],1);
    }
    else{
      cout<<Find(1,1,n,st[b],ed[b])*height[b]<<'\n';
    }
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
