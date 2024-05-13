#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

// int size = 800001;
// int tree[size];
// int arr[200001];
// int on[size];
// int off[size];
// int and_lazy[size];
// int or_lazy[size];

// void init(int node, int s, int e){
//   if(s==e){
//     tree[node] = arr[s];
//     on[node] = arr[s];
//     off[node] = ~arr[s];
//     return;
//   }
//   init(node*2,s,(s+e)/2);
//   init(node*2+1,(s+e)/2+1,e);
//   tree[node] = max(tree[node*2],tree[node*2+1]);
//   on[node] = on[node*2]&on[node*2+1];
//   off[node] = (off[node*2])&(off[node*2+1]);
// }

// void up_lazy(int node){
  
// }

// void add_up(int node, int s, int e, int l, int r, int val){
//   up_lazy(node);
//   if(l>e||r<s||((off[node]&(~val))==(~val))) return;
//   if(l<=s&&e<=r&&(on[node]&val))
// }

// void or_up(){

// }

// int Find(int node, int s, int e,int l,int r){
//   up_lazy(node,s,e);
//   if(l>e||r<s) return -1;
//   if(l<=s&&e<=r) return tree[node];
//   return Find(node*2,s,(s+e)/2,l,r)+Find(node*2+1,(s+e)/2+1,r,l,r);
// }

void solve(){
  int n,m;
  int sum=0,ans=0;
  cin>>n>>m;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    sum+=a;
    if(sum<0) sum=0;
    if(sum>=m) ans++;
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
