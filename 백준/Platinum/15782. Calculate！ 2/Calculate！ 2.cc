#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int D[100001];
int arr[100001];
int s_idx[100001];
int e_idx[100001];
int lazy[400001];
int tree[400001];
vector<int> v[100001];
int id;

void dfs(int node){
  id++;
  s_idx[node] = id;
  arr[id] = D[node];
  for(int i : v[node]) {
    if(s_idx[i]==0) dfs(i);
  }
  e_idx[node] = id;
}

void up_lazy(int node, int s, int e){
  if(lazy[node]==0) return;
  tree[node]^=((e-s+1)%2)*lazy[node];
  if(s!=e){
    lazy[node*2]^=lazy[node];
    lazy[node*2+1]^=lazy[node];
  }
  lazy[node] = 0;
  return;
}

void init(int node, int s, int e){
  if(s==e){
    tree[node] = arr[s];
    return;
  }
  init(node*2,s,(s+e)/2);
  init(node*2+1,(s+e)/2+1,e);
  tree[node] = tree[node*2]^tree[node*2+1];
}

void update(int node, int s, int e, int l, int r, int val){
  up_lazy(node,s,e);
  if(l>e||r<s) return;
  if(l<=s&&e<=r){
    tree[node]^=((e-s+1)%2)*(val);
    if(s!=e){
      lazy[node*2]^=val;
      lazy[node*2+1]^=val;
    }
    return;
  }
  update(node*2,s,(s+e)/2,l,r,val);
  update(node*2+1,(s+e)/2+1,e,l,r,val);
  tree[node] = tree[node*2]^tree[node*2+1];
}

long long Find(int node, int s, int e, int l, int r){
  up_lazy(node,s,e);
  if(r<s||l>e) return 0;
  if(l<=s&&e<=r) return tree[node];
  return Find(node*2,s,(s+e)/2,l,r)^Find(node*2+1,(s+e)/2+1,e,l,r);
}

void solve(){
  int n,m;
  cin>>n>>m;
  for(int i=1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1; i<=n; i++) cin>>D[i];
  dfs(1);
  init(1,1,n);
  while(m--){
    int a;
    cin>>a;
    if(a==1){
      int b;
      cin>>b;
      cout<<Find(1,1,n,s_idx[b],e_idx[b])<<'\n';
    }
    else{
      int b,c;
      cin>>b>>c;
      update(1,1,n,s_idx[b],e_idx[b],c);
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