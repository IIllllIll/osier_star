#include <iostream>
#include <algorithm>
using namespace std;

int w[100001];
int v[1001];
int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>w[i]>>v[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(w[i]<=j) dp[i][j] = max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][k];
    return 0;
}
