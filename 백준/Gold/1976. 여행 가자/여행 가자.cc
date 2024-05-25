#include <iostream>
using namespace std;

int arr[200][200];
int parent[200];

int Find(int x)
{
    if(x==parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Uni(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x==y)
        return;
    if(x<y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
    int n,m,temp;
    cin>>n>>m;
    for(int i=1; i<=200; i++)
        parent[i] = i;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cin>>arr[i][j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j]==1)
                Uni(i,j);
        }
    }
    for(int i=0; i<m; i++)
    {
        int a;
        cin>>a;
        if(i==0)
            temp = parent[a];
        else
        {
            if(temp!=parent[a])
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
   return 0;
}