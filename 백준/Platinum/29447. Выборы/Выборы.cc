#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int sqrt_n;

struct query{
  int idx,l,r;
  bool operator < (query &a){
    if(l/sqrt_n!=a.l/sqrt_n) return l/sqrt_n<a.l/sqrt_n;
    return r<a.r;
  }
};


int arr[100001];
int cnt[100001];
int tmp[100001];
int ans[100001];
vector<query> q;
vector<long long> v;

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
  int s=q[0].l,e=q[0].r,res=0;
  for(int i=s; i<=e; i++){
    if(tmp[cnt[arr[i]]]!=0) tmp[cnt[arr[i]]]--;
    cnt[arr[i]]++;
    tmp[cnt[arr[i]]]++;
    res = max(res,cnt[arr[i]]);
  }
  ans[q[0].idx] = res;
  for(int i=1; i<m; i++){
    while(s<q[i].l) {
      tmp[cnt[arr[s]]]--;
      if(tmp[cnt[arr[s]]]==0&&res==cnt[arr[s]]) res--;
      cnt[arr[s]]--;
      tmp[cnt[arr[s]]]++;
      s++;
    }
    while(s>q[i].l) {
      s--;
      if(tmp[cnt[arr[s]]]!=0) tmp[cnt[arr[s]]]--;
      cnt[arr[s]]++;
      tmp[cnt[arr[s]]]++;
      res = max(res,cnt[arr[s]]);
    }
    while(e<q[i].r) {
      e++;
      if(tmp[cnt[arr[e]]]!=0) tmp[cnt[arr[e]]]--;
      cnt[arr[e]]++;
      tmp[cnt[arr[e]]]++;
      res = max(res,cnt[arr[e]]);
    }
    while(e>q[i].r) {
      tmp[cnt[arr[e]]]--;
      if(tmp[cnt[arr[e]]]==0&&res==cnt[arr[e]]) res--;
      cnt[arr[e]]--;
      tmp[cnt[arr[e]]]++;
      e--;
    }
    ans[q[i].idx] = res;
  }
  for(int i=0; i<m; i++)
    cout<<ans[i]<<"\n";
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
