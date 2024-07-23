#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define X first
#define Y second

int arr[1001];

void solve(){
  int ans=0;
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  int s=arr[1],e=arr[1];
  for(int i=1; i<n; i++){
    if(arr[i]<arr[i+1]){
      e = arr[i+1];
    }
    else{
      ans = max(ans,e-s);
      s = arr[i+1];
      e = arr[i+1];
    }
  }
  ans = max(ans,e-s);
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