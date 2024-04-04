#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int s_idx[100001];
int e_idx[100001];
int id=0,n;
vector<int> v[100001];
long long up_tree[100001];
long long down_tree[100001];

void up_tree_update(int idx,long long val){
  while(idx<=n){
    up_tree[idx]+=val;
    idx+=(idx&-idx);
  }
}

long long up_Find(int idx){
  long long res=0;
  while(idx>0){
    res+=up_tree[idx];
    idx-=(idx&-idx);
  }
  return res;
}

void down_tree_update(int idx,long long val){
  while(idx<=n){
    down_tree[idx]+=val;
    idx+=(idx&-idx);
  }
}

long long down_Find(int idx){
  long long res=0;
  while(idx>0){
    res+=down_tree[idx];
    idx-=(idx&-idx);
  }
  return res;
}

void dfs(int node){
  id++;
  s_idx[node] = id;
  for(int i : v[node]){
    if(s_idx[i]==0) dfs(i);
  }
  e_idx[node] = id;
}

void solve(){
  int m;
  bool check = false;
  cin>>n>>m;
  for(int i=1; i<=n; i++){
    int a;
    cin>>a;
    if(i==1) continue;
    v[a].push_back(i);
  }
  dfs(1);
  while(m--){
    int a;
    cin>>a;
    if(a==1){
      int idx;
      long long val;
      cin>>idx>>val;
      if(!check) {
        down_tree_update(s_idx[idx],val);
        down_tree_update(e_idx[idx]+1,-1*val);
      }
      else up_tree_update(s_idx[idx],val);
    }
    else if(a==2){
      int idx;
      cin>>idx;
      cout<<up_Find(e_idx[idx])-up_Find(s_idx[idx]-1)+down_Find(s_idx[idx])<<'\n';
    }
    else check = !check;
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