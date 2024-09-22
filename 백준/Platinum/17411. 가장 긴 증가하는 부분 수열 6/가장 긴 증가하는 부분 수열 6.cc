#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

struct Node {
  long long len;
  long long cnt;
};

Node tree[4000001];

long long mod = 1e9+7;

Node mer(Node a,Node b){
  if(a.len>b.len) return a;
  else if(a.len<b.len) return b;
  else return {a.len,(a.cnt+b.cnt)%mod};
}

void update(int node, int s, int e,int idx, Node val){
  if(idx<s||idx>e) return;
  if(s==e) {
    tree[node] = mer(tree[node],val);
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

Node Find(int node, int s, int e, int l, int r){
  if(l>e||r<s) return {-1,0};
  if(l<=s&&e<=r) return tree[node];
  return mer(Find(node*2,s,(s+e)/2,l,r),Find(node*2+1,(s+e)/2+1,e,l,r));
}

void solve(){
  int n;
  cin>>n;
  long long arr[n] = {0};
  vector<long long> v;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    v.push_back(arr[i]);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=1; i<=n; i++){
    arr[i] = lower_bound(v.begin(),v.end(),arr[i])-v.begin()+1;
  }
  update(1,0,n,0,{0,1});
  for(int i=1; i<=n; i++){
    Node tmp = Find(1,0,n,0,arr[i]-1);
    tmp.len++;
    update(1,0,n,arr[i],tmp);
  }
  Node ans = Find(1,0,n,0,n);
  cout<<ans.len<<' '<<ans.cnt;
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