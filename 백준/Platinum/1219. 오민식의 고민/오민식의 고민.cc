#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<pair<pair<int,int>,long long>> v;
long long dist[51];
long long inf = 9876543210;
long long cost[51];
bool visited[51];
int e,s,n;

bool bfs(int node){
  if(node==e) return true;
  visited[node] = true;
  bool flag = false;
  for(pair<pair<int,int>,long long> next : v){
    if(next.x.x==node&&!visited[next.x.y])
      flag |= bfs(next.x.y);
  }
  return flag;
}

bool f(){
  for(int i=1; i<=n; i++) dist[i] = inf;
  dist[s] = cost[s];
  for(int i=1; i<=n; i++){
    for(pair<pair<int,int>,long long> node : v){
      if(dist[node.x.x]==inf) continue;
      if(dist[node.x.y]>dist[node.x.x]+node.y+cost[node.x.y]){
        dist[node.x.y] = dist[node.x.x]+node.y+cost[node.x.y];
        if(i==n){
          if(bfs(node.x.x))
            return false;
        }
      }
    }
  }
  return true;
}

void solve(){
  int m;
  cin>>n>>s>>e>>m;
  s++;
  e++;
  while(m--){
    int a,b;
    long long w;
    cin>>a>>b>>w;
    a++;
    b++;
    v.push_back({{a,b},w});
  }
  for(int i=1; i<=n; i++) {
    cin>>cost[i];
    cost[i] *= -1;
  }

  bool flag = f();
  //for(int i=1; i<=n; i++) cout<<dist[i]<<' ';
  if(dist[e]==inf) {
    cout<<"gg";
    return;
  }
  else if(!flag){
    cout<<"Gee";
    return;
  }
  cout<<-1*dist[e];
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
