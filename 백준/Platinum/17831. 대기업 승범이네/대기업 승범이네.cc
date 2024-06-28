#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[200001];
vector<int> v[200001];
long long dp[200001][2];

void f(int node){
  for(int next : v[node]){
    f(next);
    dp[node][0] += max(dp[next][1],dp[next][0]);
  }
  for(int next : v[node])
    dp[node][1] = max(dp[node][1],dp[node][0]-max(dp[next][1],dp[next][0])+dp[next][0]+arr[node]*arr[next]);
  return;
}

void solve(){
  int n;
  cin>>n;
  for(int i=2; i<=n; i++){
    int a;
    cin>>a;
    v[a].push_back(i);
  }
  for(int i=1; i<=n; i++)
    cin>>arr[i];
  f(1);
  cout<<max(dp[1][0],dp[1][1])<<'\n';

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
