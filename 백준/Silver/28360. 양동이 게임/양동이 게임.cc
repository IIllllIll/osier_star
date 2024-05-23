#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> v[51];
double check[51];
int in[51];

void solve(){
  int n,m;
  cin>>n>>m;
  while(m--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    in[b]++;
  }
  queue<int> q;
  q.push(1);
  check[1] = 100.0;
  for(int i=2; i<=n; i++){
    if(in[i]==0) q.push(i);
  }
  while(!q.empty()){
    int node= q.front();
    double flow = check[node]/v[node].size();
    q.pop();
    for(int i=0; i<v[node].size(); i++){
      int next = v[node][i];
      in[next]--;
      check[next] += flow;
      check[node] -= flow;
      if(in[next]==0){
        q.push({next});
      }
    }
  }
  double ans=0;
  for(int i=1; i<=n; i++){
    ans = max(ans,check[i]);
  }
  cout<<fixed;
  cout.precision(6);
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
