#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int sqrt_n;

struct query{
  int idx,l,r;
  bool operator < (query &a){
    if(l/sqrt_n!=a.l/sqrt_n) return l/sqrt_n < a.l/sqrt_n;
    return r<a.r;
  }
};

int arr[200001];
int cnt[200001];
int temp[100001];
int ans[100001];
vector<query> q;
vector<int> v;

void solve(){
  int n,m;
  cin>>n>>m;
  sqrt_n = sqrt(n);
  for(int i=1; i<=n; i++) {
    cin>>arr[i];
    arr[i]+=100000;
  }

  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r;
    q.push_back({i,l,r});
  }
  sort(q.begin(),q.end());

  int s=q[0].l,e=q[0].r,res=0;
  for(int i=s; i<=e; i++){
    if(temp[cnt[arr[i]]]!=0) temp[cnt[arr[i]]]--;
    cnt[arr[i]]++;
    temp[cnt[arr[i]]]++;
    res = max(res,cnt[arr[i]]);
  }
  ans[q[0].idx] = res;
  for(int i=1; i<m; i++){
    while(s<q[i].l) {
      temp[cnt[arr[s]]]--;
      if(temp[cnt[arr[s]]]==0&&res==cnt[arr[s]]) res--;
      cnt[arr[s]]--;
      temp[cnt[arr[s]]]++;
      s++;
    }
    while(s>q[i].l) {
      s--;
      if(temp[cnt[arr[s]]]!=0) temp[cnt[arr[s]]]--;
      cnt[arr[s]]++;
      temp[cnt[arr[s]]]++;
      res = max(res,cnt[arr[s]]);
    }
    while(e<q[i].r) {
      e++;
      if(temp[cnt[arr[e]]]!=0) temp[cnt[arr[e]]]--;
      cnt[arr[e]]++;
      temp[cnt[arr[e]]]++;
      res = max(res,cnt[arr[e]]);
    }
    while(e>q[i].r) {
      temp[cnt[arr[e]]]--;
      if(temp[cnt[arr[e]]]==0&&res==cnt[arr[e]]) res--;
      cnt[arr[e]]--;
      temp[cnt[arr[e]]]++;
      e--;
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
