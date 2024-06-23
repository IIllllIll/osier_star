#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long arr[101010];
int sqrt_n=300;

struct query{
  int idx,l,r;
  bool operator < (query &a){
    if(l/sqrt_n!=a.l/sqrt_n) return l/sqrt_n<a.l/sqrt_n;
    return r<a.r;
  }
};

vector<query> q;
long long cnt[1<<21];
long long ans[101010];

void solve(){
  int n,k;
  cin>>n>>k;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    arr[i]^=arr[i-1];
  }
  int m;
  cin>>m;
  for(int i=0; i<m; i++){
    long long l,r;
    cin>>l>>r;
    q.push_back({i,l-1,r});
  }
  sort(q.begin(),q.end());
  long long s = q[0].l;
  long long e = q[0].r;
  long long res=0;
  for(int i=s; i<=e; i++){
    res += cnt[arr[i]^k];
    cnt[arr[i]]++;
  }
  ans[q[0].idx] = res;
  for(int i=1; i<m; i++){
    while(e<q[i].r){
      e++;
      res += cnt[arr[e]^k];
      cnt[arr[e]]++;
    }
    while(s>q[i].l){
      s--;
      res += cnt[arr[s]^k];
      cnt[arr[s]]++;
    }
    while(s<q[i].l){
      cnt[arr[s]]--;
      res -= cnt[arr[s]^k];
      s++;
    }
    while(e>q[i].r){
      cnt[arr[e]]--;
      res -= cnt[arr[e]^k];
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
