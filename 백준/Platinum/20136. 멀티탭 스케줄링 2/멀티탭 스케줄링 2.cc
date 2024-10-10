#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

deque<int> idx[500001];
pair<int,int> tree[2000001];

void init(int node, int s, int e){
  if(s==e){
    tree[node] = {s,0};
    return;
  }
  init(node*2,s,(s+e)/2);
  init(node*2+1,(s+e)/2+1,e);
  if(tree[node*2].y>tree[node*2+1].y) tree[node] = tree[node*2];
  else tree[node] = tree[node*2+1];
}

void update(int node, int s, int e, int idx, int val){
  if(idx<s||idx>e) return;
  if(s==e) {
    tree[node] = {idx,val};
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  if(tree[node*2].y>tree[node*2+1].y) tree[node] = tree[node*2];
  else tree[node] = tree[node*2+1];
}

pair<int, int> Find(int node, int s, int e, int l,int r){
  if(l>e||r<s) return {0,0};
  if(l<=s&&e<=r) return tree[node];
  auto a = Find(node*2,s,(s+e)/2,l,r);
  auto b = Find(node*2+1,(s+e)/2+1,e,l,r);
  if(a.y>b.y) return a;
  else return b;
}

void output(int val, int n){
    cout<<val<<" / ";
    for(int j=1; j<=n+1;j++){
      if(Find(1,1,n+1,j,j).y==0) continue;
      cout<<Find(1,1,n+1,j,j).x<<' '<<(Find(1,1,n+1,j,j).y==99?99:Find(1,1,n+1,j,j).y-1)<<' ';
    }
    cout<<'\n';
}

void solve(){
  int k,n,ans=0;
  cin>>k>>n;
  init(1,1,n+1);
  vector<int> arr;
  arr.push_back(0);
  for(int i=1; i<=n; i++){
    int a;
    cin>>a;
    if(arr.back()==a) continue;
    else arr.push_back(a);
  }

  for(int i=1; i<arr.size(); i++){
    idx[arr[i]].push_back(i);
  }
  
  int cnt=0,i;
  for(i=1; i<arr.size(); i++){
    int val = arr[i];
    idx[val].pop_front();
    int idx_val;
    if(idx[val].empty()) idx_val = n+1;
    else idx_val = idx[val].front();
    
    auto se = Find(1,1,n+1,val,val);
    if(se.y==0) cnt++;
    update(1,1,n+1,val,idx_val);
    //output(val,n);
    if(cnt==k) break;
  }

  i++;
  for(; i<arr.size(); i++){
    int val = arr[i];
    idx[val].pop_front();
    int idx_val;
    if(idx[val].empty()) idx_val = n+1;
    else idx_val = idx[val].front();
    //cout<<val<<' '<<idx_val<<'\n';
    auto se = Find(1,1,n+1,val,val);
    if(se.y!=0) {
      update(1,1,n+1,val,idx_val);
      //output(val,n);
      continue;
    }

    ans++;
    auto mx = tree[1];
    update(1,1,n+1,mx.x,0);
    update(1,1,n+1,val,idx_val);
    
    //output(val,n);
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
