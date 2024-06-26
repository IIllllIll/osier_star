#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long arr[500001];
long long mn[500001];
long long res_mn[500001];

void solve(){
  int n,k;
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    cin>>arr[i];
  }
  mn[1] = arr[1]-k;
  res_mn[1] = arr[n]-k;
  for(int i=2; i<=n; i++){
    mn[i] = min(arr[i]-(k*i),mn[i-1]);
    res_mn[i] = min(res_mn[i-1],arr[n-i+1]-(k*i));
  }
  long long ans = -1*1e10;
  for(int i=2; i<=n; i++){
    ans = max(ans,(arr[i]-(i*k))-mn[i-1]);
  }
  for(int i=2; i<=n; i++){
    ans = max(ans,arr[n-i+1]-(i*k)-res_mn[i-1]);
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
