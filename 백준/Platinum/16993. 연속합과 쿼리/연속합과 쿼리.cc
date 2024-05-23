#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long v = -1e15;

typedef struct {
  long long lm;
  long long rm;
  long long m;
  long long all;
}sum;

long long arr[100001];
sum tree[400001];

sum mer(sum a, sum b){
  sum res;
  res.lm = max(a.lm,a.all+b.lm);
  res.rm = max(b.rm,b.all+a.rm);
  res.m = max(a.m,max(b.m,a.rm+b.lm));
  res.all = a.all+b.all;
  return res;
}

void init(int node, int s, int e){
  if(s==e){
    tree[node].lm = arr[s];
    tree[node].rm = arr[s];
    tree[node].m = arr[s];
    tree[node].all = arr[s];
    return;
  }
  init(node*2,s,(s+e)/2);
  init(node*2+1,(s+e)/2+1,e);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

sum Find(int node, int s, int e, int l, int r){
  if(l>e||r<s) {
    sum res;
    res = {v,v,v,0};
    return res;
  }
  if(l<=s&&e<=r){
    return tree[node];
  }
  return mer(Find(node*2,s,(s+e)/2,l,r),Find(node*2+1,(s+e)/2+1,e,l,r));
}

void update(int node, int s, int e, int idx, int val){
  if(idx<s||idx>e) return;
  if(s==e){
    tree[node] = {val,val,val,val};
    arr[s] = val;
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>arr[i];
  init(1,1,n);
  int k;
  cin>>k;
  for(int i=0; i<k; i++){
    int a,b;
    cin>>a>>b;
    sum ans = Find(1,1,n,a,b);
    cout<<max(ans.lm,max(ans.rm,max(ans.m,ans.all)))<<'\n';
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