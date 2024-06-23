#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long arr[10001];
long long ans=0;

void buy_3(int idx){
  int mn = min(arr[idx],min(arr[idx+1],arr[idx+2]));
  ans += 7*mn;
  arr[idx]-=mn;
  arr[idx+1]-=mn;
  arr[idx+2]-=mn;
}

void buy_2(int idx){
  int mn = min(arr[idx],arr[idx+1]);
  ans += 5*mn;
  arr[idx]-=mn;
  arr[idx+1]-=mn;
}

void buy_1(int idx){
  ans += arr[idx]*3;
  arr[idx] = 0;
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  for(int i=1; i<=n; i++){
    if(arr[i+1]>arr[i+2]){
      int mn = min(arr[i],arr[i+1]-arr[i+2]);
      ans += mn*5;
      arr[i]-=mn;
      arr[i+1]-=mn;
      buy_3(i);
      buy_1(i);
    }
    else{
      buy_3(i);
      buy_2(i);
      buy_1(i);
    }
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
