#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

typedef struct {
  long long mx,mn,sum;
}ans;

long long arr[100001];
ans tree[400001];
point lazy[400001];

ans mer(ans a, ans b){
  return {max(a.mx,b.mx),min(a.mn,b.mn),a.sum+b.sum};
}

void init(int node, int s, int e){
  if(s==e){
    tree[node] = {arr[s],arr[s],arr[s]};
    return;
  }
  int m = s + e >>1;
  init(node*2,s,m);
  init(node*2+1,m+1,e);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

void up_lazy(int node, int s, int e){
  if(!lazy[node].x&&!lazy[node].y) return;
  if(!lazy[node].y){
    tree[node].mx += lazy[node].x;
    tree[node].mn += lazy[node].x;
    tree[node].sum += (e-s+1)*lazy[node].x;
    if(s^e){
      lazy[node*2].x += lazy[node].x;
      lazy[node*2+1].x += lazy[node].x;
    }
  }
  else{
    tree[node].mx = lazy[node].x+lazy[node].y;
    tree[node].mn = tree[node].mx;
    tree[node].sum = (e-s+1)*(tree[node].mx);
    if(s^e){
      lazy[node*2] = {lazy[node].x,lazy[node].y};
      lazy[node*2+1] = lazy[node*2];
    }
  }
  lazy[node] = {0,0};
}

long long Find(int node, int s, int e, int l, int r){
  up_lazy(node,s,e);
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) return tree[node].sum;
  int m = s+e>>1;
  return Find(node*2,s,m,l,r)+Find(node*2+1,m+1,e,l,r);
}

void add(int node, int s, int e, int l, int r, long long val){
  up_lazy(node,s,e);
  if(l>e||r<s) return;
  if(l<=s&&e<=r){
    lazy[node].x += val;
    up_lazy(node,s,e);
    return;
  }
  int m = s+e>>1;
  add(node*2,s,m,l,r,val);
  add(node*2+1,m+1,e,l,r,val);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

void Sqrt(int node, int s, int e, int l,int r){
  up_lazy(node,s,e);
  if(l>e||r<s) return;
  if(l<=s&&e<=r){
    if(floor(sqrt(tree[node].mx))==floor(sqrt(tree[node].mn))){
      lazy[node].y = floor(sqrt(tree[node].mx));
      up_lazy(node,s,e);
      return;
    }
    if(tree[node].mn+1==tree[node].mx){
      lazy[node].x = floor(sqrt(tree[node].mn))-tree[node].mn;
      up_lazy(node,s,e);
      return;
    }
  }
  Sqrt(node*2,s,(s+e)/2,l,r);
  Sqrt(node*2+1,(s+e)/2+1,e,l,r);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  init(1,1,n);
  int m;
  cin>>m;
  while(m--){
    int a;
    cin>>a;
    if(a==1){
      long long l,r,val;
      cin>>l>>r>>val;
      add(1,1,n,l,r,val);
    }
    else if(a==2){
      long long l,r;
      cin>>l>>r;
      Sqrt(1,1,n,l,r);
    }
    else{
      long long l,r;
      cin>>l>>r;
      cout<<Find(1,1,n,l,r)<<'\n';
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