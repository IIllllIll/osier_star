#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int arr[2];
  arr[1]=0;
  arr[0]=0;
  for(int i=0; i<3; i++){
    int a;
    cin>>a;
    arr[--a]++;
  }
  if(arr[0]>arr[1]) cout<<1;
  else cout<<2;
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