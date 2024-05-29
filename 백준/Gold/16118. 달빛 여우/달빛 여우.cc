#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long inf = 9876543210;
long long dist1[4001];
long long dist2[8001];
bool visited[8001];
vector<pair<int,long long>> v[4001];
vector<pair<int,long long>> even_odd[8001];
int n;

void f(){
  for(int i=1; i<=n; i++){
    dist1[i] = inf;
    dist2[i] = dist2[i+n] = inf;
  }
  dist1[1] = 0;
  dist2[1] = 0;
  priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> q;
  q.push({0,1});
  while(!q.empty()){
    int node = q.top().y;
    long long cost = q.top().x;
    q.pop();
    if(visited[node]) continue;
    visited[node] = true;
    for(int i=0; i<v[node].size(); i++){
      int next = v[node][i].x;
      long long w = v[node][i].y;
      if(dist1[next]>cost+w){
        dist1[next] = cost+w;
        q.push({dist1[next],next}); 
      }
    }
  }
  memset(visited,false,sizeof(visited));
  q.push({0,1});
  while(!q.empty()){
    int node = q.top().y;
    long long cost = q.top().x;
    //if(dist2[node]<cost) continue;
    q.pop();
    if(visited[node]) continue;
    visited[node] = true;
    for(int i=0; i<even_odd[node].size(); i++){
      int next = even_odd[node][i].x;
      long long w = even_odd[node][i].y;
      if(dist2[next]>cost+w){
        dist2[next] = cost+w;
        q.push({dist2[next],next}); 
      }
    }
  }
}

void solve(){
  int m;
  cin>>n>>m;
  while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    c*=2;
    v[a].push_back({b,c});
    v[b].push_back({a,c});

    even_odd[a+n].push_back({b,c*2});
    even_odd[b+n].push_back({a,c*2});
    even_odd[a].push_back({b+n,c/2});
    even_odd[b].push_back({a+n,c/2});
  }
  f();
  int cnt=0;
  for(int i=1; i<=n; i++){
    if(dist1[i]<min(dist2[i],dist2[i+n])) cnt++;
  }
  cout<<cnt;
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
