#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int cnt[1000001];
int arr[1000001];
int ans[1000001];
vector<int> v;
int sqrt_n;

struct query{
  int idx,l,r;
  bool operator < (query &a){
    if(l/sqrt_n!=a.l/sqrt_n) return l/sqrt_n<a.l/sqrt_n;
    return r<a.r;
  }
};

vector<query> q;

void solve(){
  int n;
  cin>>n;
  sqrt_n = sqrt(n);
  for(int i=1; i<=n; i++) {
    cin>>arr[i];
    v.push_back(arr[i]);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=1; i<=n; i++){
    int idx = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
    arr[i] = idx;
  }
  int m;
  cin>>m;
  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r;
    q.push_back({i,l,r});
  }
  sort(q.begin(),q.end());
  int s = q[0].l, e = q[0].r, res=0;
  for(int i=s; i<=e; i++){
    if(cnt[arr[i]]==0) res++;
    cnt[arr[i]]++;
  }
  ans[q[0].idx] = res;
  for(int i=1; i<m; i++){
    while(s<q[i].l){
      cnt[arr[s]]--;
      if(cnt[arr[s]]==0) res--;
      s++;
    }
    while(s>q[i].l){
      s--;
      if(cnt[arr[s]]==0) res++;
      cnt[arr[s]]++;
    }
    while(e>q[i].r){
      cnt[arr[e]]--;
      if(cnt[arr[e]]==0) res--;
      e--;
    }
    while(e<q[i].r){
      e++;
      if(cnt[arr[e]]==0) res++;
      cnt[arr[e]]++;
    }
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
