#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

int par[2001];
vector<pair<int,pair<int,int>>> v;

int Find(int x)
{
    if(x==par[x]) return x;
    else return par[x] =Find(par[x]);
}

void Uni(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a==b) return ;
    else if(a<b) par[b] =a;
    else par[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,e,s,ans=0;
    cin>>n>>e>>s;
    for(int i=1; i<=n; i++)
        par[i] = i;
    for(int i=0; i<e; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v.push_back({w,{x,y}});
    }
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<e; i++)
    {
        if(Find(v[i].second.first)!=Find(v[i].second.second))
        {
            Uni(v[i].second.first,v[i].second.second);
            ans+=v[i].first;
        }
    }
    cout<<ans;
    return 0;
}
