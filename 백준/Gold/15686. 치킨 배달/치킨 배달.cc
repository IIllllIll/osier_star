#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<pair<int,int>> v;
int n,m,inf=97654321;
vector<pair<int,int>> mp;
int g=97654321;
bool check[14];

int f(pair<int,int> a, pair<int,int> b){
  return abs(a.x-b.x)+abs(a.y-b.y);
}

void dfs(int node, int cnt){

  if(node+1>v.size()){
    return;
  }

  if(cnt==m){
    int res=0;
    vector<int> ans;
    for(int i=0; i<mp.size(); i++)
      ans.push_back(inf);
    for(int i=0; i<v.size(); i++){
      if(!check[i]) continue;

      for(int j=0; j<ans.size(); j++){
        ans[j] = min(ans[j],f(v[i],mp[j]));
      }
    }

    for(int i=0; i<ans.size(); i++)
      res+=ans[i];
    
    g = min(g,res);
    return;
  }

  for(int i=node+1; i<v.size(); i++){
    check[i] = true;
    dfs(i,cnt+1);
    check[i] = false;
  }
}

void solve(){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int a;
      cin>>a;
      if(a==2)
        v.push_back({i,j});
      if(a==1)
        mp.push_back({i,j});
    }
  }
  dfs(-1,0);
  cout<<g;
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