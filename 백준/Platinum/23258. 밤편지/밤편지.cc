#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long dist[301][301][301];
long long inf = 987654321;

void solve(){
  int n,m;
  cin>>n>>m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      long long w;
      cin>>w;
      if(w==0) dist[0][i][j] = inf;
      else dist[0][i][j] = w;
    }
    dist[0][i][i] = 0;
  }
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        dist[k][i][j] = min(dist[k-1][i][j],dist[k-1][i][k]+dist[k-1][k][j]);
      }
    }
  }
  while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    if(dist[a-1][b][c]==inf) cout<<"-1\n";
    else cout<<dist[a-1][b][c]<<'\n';
  }
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
