#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
vector <int> v[1001];
int dist[1001];
queue <int> q;

int main() {
    ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   int n,e;
   cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        dist[y]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(dist[i]==0)
            q.push(i);
        dp[i]=1;
    }
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0; i<v[temp].size(); i++)
        {
            int next = v[temp][i];
            dp[next] = dp[temp]+1;
            dist[next]--;
            if(dist[next]==0)
                q.push(next);
        }
    }
    for(int i=1; i<=n; i++)
        cout<<dp[i]<<" ";
   return 0;
}