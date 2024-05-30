#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int inf = 987654321;
int dist[1001];
int distx[1001];
vector<pair<int,int>> v[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int di(int x,int y)
{
    if(x==y)
        return 0;
    for(int i=1; i<=1000; i++)
        dist[i] = inf;
    dist[x] = 0;
    q.push({x,0});
    while(!q.empty())
    {
        int tempc = q.top().second;
        int tempn = q.top().first;
        q.pop();
        for(int i=0; i<v[tempn].size(); i++)
        {
            int next = v[tempn][i].first;
            int nc = v[tempn][i].second;
            if(dist[next]>tempc+nc)
            {
                dist[next] = tempc+nc;
                q.push({next,dist[next]});
            }
        }
    }
    return dist[y];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n,m,x,ans=0;
  cin>>n>>m>>x;
  for(int i=1; i<=n; i++)
    distx[i] = inf;
  for(int i=0; i<m; i++){
    int a,b,w;
    cin>>a>>b>>w;
    v[a].push_back({b,w});
  }
  distx[x] = 0;
  q.push({x,0});
  while(!q.empty()){
    int cost = q.top().second;
    int node = q.top().first;
    q.pop();
    for(int i=0; i<v[node].size(); i++){
      int next = v[node][i].first;
      int w = v[node][i].second;
      if(distx[next]>cost+w){
        distx[next] = cost+w;
        q.push({next,distx[next]});
      }
    }
  }
  for(int i=1; i<=n; i++){
    if(i==x) continue;
    int cost = di(i,x)+distx[i];
    //cout<<i<<" / "<<di(i,x)<<" "<<di(x,i)<<"\n";
    if(cost>ans)
      ans = cost;
  }
  cout<<ans;
  return 0;
}