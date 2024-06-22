#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[100001];
const int sqrt_n=300,sz=(100001/sqrt_n+10);
int n;
struct query{
  int idx,l,r;
  bool operator < (query &a){
    if(l/sqrt_n!=a.l/sqrt_n) return l/sqrt_n<a.l/sqrt_n;
    return r<a.r;
  }
};

vector<query> q;
deque<int> de[200001];
int cnt[200001];
int bucket[sz];
int ans[100001];

void add(int idx, int flag){
  int val = arr[idx];
  int res=0;
  if(!de[val].empty()){
    res = de[val].back()-de[val].front();
    cnt[res]--;
    bucket[res/sqrt_n]--;
  }
  if(!flag) de[val].push_front(idx);
  else de[val].push_back(idx);
  res = de[val].back()-de[val].front();
  cnt[res]++;
  bucket[res/sqrt_n]++;
}

void sub(int idx, int flag){
  int val = arr[idx];
  int res = de[val].back()-de[val].front();
  cnt[res]--;
  bucket[res/sqrt_n]--;
  if(!flag) de[val].pop_front();
  else de[val].pop_back();
  if(!de[val].empty()){
    res = de[val].back()-de[val].front();
    cnt[res]++;
    bucket[res/sqrt_n]++;
  }
}

int Find(){
  for(int i=sz-1; i>=0; i--){
    if(bucket[i]==0) continue;
    for(int j=sz-1; j>=0; j--){
      if(cnt[(i*sqrt_n)+j]>0) 
        return (i*sqrt_n)+j;
    }
  }
  return 0;
}

void solve(){
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<=n; i++) arr[i] += arr[i-1];
  for(int i=0; i<=n; i++) arr[i] += 100000;
  int m;
  cin>>m;
  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r;
    q.push_back({i,l-1,r});
  }
  sort(q.begin(),q.end());
  int s=q[0].l,e=q[0].r;
  for(int i=s; i<=e; i++)
    add(i,1);
  ans[q[0].idx] = Find();
  for(int i=1; i<m; i++){
    while(e<q[i].r){
      e++;
      add(e,1);
    }
    while(s>q[i].l){
      s--;
      add(s,0);
    }
    while(s<q[i].l){
      sub(s,0);
      s++;
    }
    while(e>q[i].r){
      sub(e,1);
      e--;
    }
    ans[q[i].idx] = Find();
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
