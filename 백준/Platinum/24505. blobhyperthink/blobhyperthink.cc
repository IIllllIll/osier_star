#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long dp[101010][12];
long long arr[101010];
long long mod = 1e9+7;
long long tree[401010];

void update(int node, int s, int e,int idx, int val){
  if(idx<s||idx>e) return;
  if(s==e) {
    tree[node] += val;
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  tree[node] = tree[node*2]+tree[node*2+1];
}

long long Find(int node, int s, int e, int l, int r){
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) return tree[node];
  return Find(node*2,s,(s+e)/2,l,r)+Find(node*2+1,(s+e)/2+1,e,l,r);
}

// void init(int node, int s, int e){
//   if(s==e){
//     tree[node] = 0;
//     return;
//   }
//   init(node*2,s,(s+e)/2);
//   init(node*2+1,(s+e)/2+1,e);
//   tree[node] = tree[node*2]+tree[node*2+1];
// }

void solve(){
  int n;
  long long ans=0;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  update(1,0,n,0,1);
  for(int i=1; i<=11; i++){
    for(int j=1; j<=n; j++){
      update(1,0,n,arr[j],dp[j][i-1]);
      dp[j][i] = (Find(1,0,n,0,arr[j]-1))%mod;
    }
    memset(tree,0,sizeof(tree));
  }
  for(int i=1; i<=n; i++){
    ans += dp[i][11];
    ans%=mod;
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
