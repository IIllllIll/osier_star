#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

const int sqrt_n=300;

struct query{
  int idx,l,r;
  bool operator < (query &a){
    if(l/sqrt_n!=a.l/sqrt_n) return l<a.l;
    return r<a.r;
  }
};

long long arr[100001];
vector<query> q;
long long ans[100001];
long long tree[100001];
long long res;

void update(int n, int idx, int val){
  while(idx<=n){
    tree[idx] += val;
    idx += (idx&-idx);
  }
  return;
}

long long Find(int idx){
  long long res=0;
  while(idx>0){
    res += tree[idx];
    idx-=(idx&-idx);
  }
  return res;
}

void add(int idx, int flag){
  if(!flag) res += Find(arr[idx]-1);
  else res += Find(100000)-Find(arr[idx]);
  update(100000,arr[idx],1);
}

void sub(int idx, int flag){
  update(100000,arr[idx],-1);
  if(!flag) res -= Find(arr[idx]-1);
  else res -= Find(100000)-Find(arr[idx]);
}

void solve(){
  int n,m;
  cin>>n>>m;
  vector<long long> v;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    v.push_back(arr[i]);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=1; i<=n; i++){
    int idx = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
    arr[i] = idx+1;
  }
  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r;
    q.push_back({i,l,r});
  }
  sort(q.begin(),q.end());
  int s=q[0].l,e=q[0].r;
  for(int i=s; i<=e; i++){
    add(i,1);
  }
  ans[q[0].idx] = res;
  for(int i=1; i<m; i++){
    while(q[i].l<s) add(--s,0);
    while(q[i].r>e) add(++e,1);
    while(q[i].l>s) sub(s++,0);
    while(q[i].r<e) sub(e--,1);
    ans[q[i].idx] = res;
  }
  for(int i=0; i<m; i++)
    cout<<ans[i]<<'\n';
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
