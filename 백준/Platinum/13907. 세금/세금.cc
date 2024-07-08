#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second
#define pp pair<long long,pair<int,int>>

int tax[30001];
long long dist[1001][1001];
long long inf = 1e10;
vector<pair<int,int>> v[1001];
int n;

void f(int s){
  for(int i=1; i<=n; i++){
    for(int j=0; j<n; j++)
      dist[i][j] = inf;
  }
  priority_queue<pp,vector<pp>,greater<pp>> q;
  q.push({0,{s,0}});
  dist[s][0]=0;
  while(!q.empty()){
    pp node = q.top();
    q.pop();
    if(dist[node.y.x][node.y.y]<node.x) continue;
    for(pair<int,int> next : v[node.y.x]){
      long long cost = node.x+next.y;
      long long cnt = node.y.y+1;
      if(dist[next.x][cnt]>cost){
        dist[next.x][cnt] = cost;
        q.push({cost,{next.x,cnt}});
      }
    }
  }
}

void solve(){
  int m,k;
  cin>>n>>m>>k;
  int s,e;
  cin>>s>>e;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  f(s);
  for(int i=1; i<=k; i++)
    cin>>tax[i];
  for(int i=0; i<=k; i++){
    long long ans = inf;
    for(int j=1; j<n; j++){
      dist[e][j] += tax[i]*j;
      ans = min(ans,dist[e][j]);
    }
    cout<<ans<<'\n';
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