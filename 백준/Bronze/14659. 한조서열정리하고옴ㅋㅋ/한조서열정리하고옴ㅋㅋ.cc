#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int n;
  cin>>n;
  int ans=0;
  int arr[30001];
  for(int i=1; i<=n; i++)
    cin>>arr[i];
  for(int i=1; i<=n; i++){
    int cnt=1;
    for(;i+cnt<=n; cnt++){
      if(arr[i+cnt]>arr[i]) break;
    }
    cnt-=1;
    ans = max(ans,cnt);
    //cout<<cnt;
    i+=cnt;
  }
  cout<<ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int ct=1;
  //cin>>ct;
  while(ct--) solve();
  return 0;
}
