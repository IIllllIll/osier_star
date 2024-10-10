#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

deque<int> idx[101];

void solve(){
  int k,n,ans=0;
  cin>>k>>n;
  vector<int> lis;
  vector<int> arr;
  for(int i=1; i<=n; i++){
    int a;
    cin>>a;
    if(arr.empty()) arr.push_back(a);
    else{
      if(arr.back()==a) continue;
      else arr.push_back(a);
    }
  }
  n = arr.size();
  for(int i=0; i<n; i++)
    idx[arr[i]].push_back(i);
  for(int i=0; i<n; i++){
    int val = arr[i];
    idx[val].pop_front();
    if(lis.size()<k){
      bool check = 1;
      for(int next : lis){
        if(next==val) {
          check = 0;
          break;
        }
      }
      if(check) lis.push_back(val);
    }
    else{
      bool check = 1;
      for(int next : lis){
        if(next==val) {
          check = 0;
          break;
        }
      }
      if(check) {
        ans++;
        int mx=0;
        int mx_idx=0;
        bool flag = 0;
        for(int j=0; j<k; j++){
          if(idx[lis[j]].empty()){
            lis[j] = val;
            flag = 1;
            break;
          }
          if(idx[lis[j]].front()>mx){
            mx = idx[lis[j]].front();
            mx_idx = j;
          }
        }
        if(!flag) {
          lis[mx_idx] = val;
        }
      }
    }
    // cout<<val<<" / ";
    // for(int j : lis) cout<<j<<' ';
    // cout<<'\n';
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
