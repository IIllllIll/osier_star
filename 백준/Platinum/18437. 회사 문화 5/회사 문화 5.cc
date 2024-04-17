#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int s_idx[100001];
int e_idx[100001];
int id=0,n;
vector<int> v[100001];

void dfs(int node){
  id++;
  s_idx[node] = id;
  for(int i : v[node]){
    if(s_idx[i]==0) dfs(i);
  }
  e_idx[node] = id;
}

int lazy[400001];
int tree[400001];

void init(int node, int s, int e){
  if(s==e){
    tree[node] = 1;
    return;
  }
  init(node*2,s,(s+e)/2);
  init(node*2+1,(s+e)/2+1,e);
  tree[node] = tree[node*2]+tree[node*2+1];
}

void up_lazy(int node, int s, int e){
  if(lazy[node]==0) return;
  if(lazy[node]==-1) tree[node] = 0;
  else tree[node] = e-s+1;
  if(s!=e){
    lazy[node*2] = lazy[node];
    lazy[node*2+1] = lazy[node];
  }
  lazy[node]=0;
  return;
}

void update(int node, int s, int e, int l, int r, int val){
  up_lazy(node,s,e);
  if(l>e||r<s) return;
  if(l<=s&&e<=r){
    lazy[node] = val;
    up_lazy(node,s,e);
    return;
  }
  update(node*2,s,(s+e)/2,l,r,val);
  update(node*2+1,(s+e)/2+1,e,l,r,val);
  tree[node] = tree[node*2]+tree[node*2+1];
}

int Find(int node, int s, int e, int l, int r){
  up_lazy(node,s,e);
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) return tree[node];
  return Find(node*2,s,(s+e)/2,l,r)+Find(node*2+1,(s+e)/2+1,e,l,r); 
}

void solve(){
  int m;
  cin>>n;
  for(int i=1; i<=n; i++){
    int a;
    cin>>a;
    if(i==1) continue;
    v[a].push_back(i);
  }
  dfs(1);
  init(1,1,n);
  cin>>m;
  while(m--){
    int a,idx;
    cin>>a>>idx;
    if(a==1){
      update(1,1,n,s_idx[idx]+1,e_idx[idx],1);
    }
    else if(a==2){
      update(1,1,n,s_idx[idx]+1,e_idx[idx],-1);
    }
    else{
      cout<<Find(1,1,n,s_idx[idx]+1,e_idx[idx])<<'\n';
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