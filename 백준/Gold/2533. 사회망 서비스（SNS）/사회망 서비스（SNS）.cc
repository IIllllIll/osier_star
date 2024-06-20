#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> v[1000001];
bool check[1000001];
long long ans;

bool dfs(int s){
  bool flag = false;
  for(int node : v[s]){
    if(!check[node]){
      check[node] = 1;
      flag |= !(dfs(node));
    }
  }
  if(flag) ans++;

  return flag;
}

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  check[1] = true;
  dfs(1);
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
