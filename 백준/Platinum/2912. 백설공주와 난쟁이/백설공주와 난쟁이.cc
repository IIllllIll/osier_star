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

vector<query> q;
int arr[300001];
int cnt[10001];
int ans[10001];

int check(int c,int s, int e){
  for(int i=1; i<=c; i++){
    if(cnt[i]*2>(e-s+1)) {
      return i;
    }
  }
  return -1;
}

void solve(){
  int n,c;
  cin>>n>>c;
  sqrt_n = sqrt(n);
  for(int i=1; i<=n; i++) cin>>arr[i];
  int m;
  cin>>m;
  for(int i=0; i<m; i++){
    int l,r;
    cin>>l>>r;
    q.push_back({i,l,r});
  }
  sort(q.begin(),q.end());
  int s=q[0].l,e=q[0].r;
  for(int i=s; i<=e; i++){
    cnt[arr[i]]++;
  }
  ans[q[0].idx] = check(c,s,e);
  for(int i=1; i<m; i++){
    while(s<q[i].l){
      cnt[arr[s]]--;
      s++;
    }
    while(s>q[i].l){
      s--;
      cnt[arr[s]]++;
    }
    while(e>q[i].r){
      cnt[arr[e]]--;
      e--;
    }
    while(e<q[i].r){
      e++;
      cnt[arr[e]]++;
    }
    ans[q[i].idx] = check(c,s,e);
  }
  for(int i=0; i<m; i++){
    if(ans[i]==-1) cout<<"no\n";
    else cout<<"yes "<<ans[i]<<'\n';
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