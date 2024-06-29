#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second


void solve(){
  int arr[21];
  for(int i=1; i<=20; i++)
    arr[i] = i;
  for(int k=0; k<10; k++){
    int l,r;
    cin>>l>>r;
    vector<int> v;
    for(int i=l; i<=r; i++)
      v.push_back(arr[i]);
    reverse(v.begin(),v.end());
    for(int i=l; i<=r; i++){
      arr[i] = v[i-l];
    }
  }
  for(int i=1; i<=20; i++)
    cout<<arr[i]<<' ';
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
