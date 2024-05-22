#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int k;

int and_tree[800001];
int tree[800001];
int arr[800001];

void init(int node, int s, int e){
  if(s==e){
    tree[node] = (arr[s]==k?1:0);
    and_tree[node] = arr[s];
    return;
  }
  init(node*2,s,(s+e)/2);
  init(node*2+1,(s+e)/2+1,e);
  tree[node] = tree[node*2]+tree[node*2+1];
  and_tree[node] = and_tree[node*2]&and_tree[node*2+1];
  
}

void update(int node, int s, int e, int l, int r, int val){
  
  if(l>e||r<s||((and_tree[node]&val)==val)) return;
  
  if(s==e){
    arr[s] |= val;
    tree[node] = (arr[s]==k?1:0);
    and_tree[node] = arr[s];
    //cout<<and_tree[node]<<' ';
    return;
  }
  update(node*2,s,(s+e)/2,l,r,val);
  update(node*2+1,(s+e)/2+1,e,l,r,val);
  tree[node] = tree[node*2]+tree[node*2+1];
  and_tree[node] = and_tree[node*2]&and_tree[node*2+1];

}

int Find(int node, int s, int e, int l, int r){
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) return tree[node];
  return Find(node*2,s,(s+e)/2,l,r)+Find(node*2+1,(s+e)/2+1,e,l,r);
}

void solve(){
  int n;
  cin>>n>>k;
  for(int i=1; i<=n; i++) cin>>arr[i];
  init(1,1,n);
  int m;
  cin>>m;
  while(m--){
    int a;
    cin>>a;
    if(a==1){
      int l,r,val;
      cin>>l>>r>>val;
      update(1,1,n,l,r,val);
    }
    else{
      int l,r;
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
