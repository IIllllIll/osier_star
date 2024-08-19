#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long inf = 0x3F3F3F3F3F3F3F3F;

void solve(){
  int p,n,m;
  cin>>p>>n>>m;
  long long mp[n+1][n+1]={0};
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(mp[i][j]==0) mp[i][j] = inf;
    }
  }
  vector<int> v;
  for(int i=0; i<p; i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  while(m--){
    long long a,b,c;
    cin>>a>>b>>c;
    mp[a][b] = min(c,mp[a][b]);
    mp[b][a] = min(c,mp[b][a]);
  }
  for(int i=1; i<=n; i++) mp[i][i] = 0;
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++)
        mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
    }
  }
  long long dist = inf;
  long long idx = 0;
  for(int i=1; i<=n; i++){
    long long res=0;
    bool check= 0;
    for(int a:v){
      if(mp[i][a]>=inf) {
        check = 1;
        break;
      }
      res += mp[i][a]*mp[i][a];
    }
    if((!check)&&dist>res){
      dist = res;
      idx = i;
    }
  }
  cout<<idx<<' '<<dist<<'\n';
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int ct=1;
  cin>>ct;
  while(ct--) solve();
  return 0;
}