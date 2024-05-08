#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[4];

long long dp[61][61][61];

long long f(int a, int b, int c, long long cnt){
  if(a<=0) a=0;
  if(b<=0) b=0;
  if(c<=0) c=0;
  if(a<=0&&b<=0&&c<=0) return cnt;
  if(dp[a][b][c]!=0) return dp[a][b][c];

  if((a<=0&&b<=0))
    return dp[a][b][c] = f(a,b,c-9,cnt+1);
  else if(b<=0&&c<=0)
    return dp[a][b][c] = f(a-9,b,c,cnt+1);
  else if(a<=0&&c<=0)
    return dp[a][b][c] = f(a,b-9,c,cnt+1);
  else if(a<=0)
    return dp[a][b][c] = min(f(a,b-9,c-3,cnt+1),f(a,b-3,c-9,cnt+1));
  else if(b<=0)
    return dp[a][b][c] = min(f(a-3,b,c-9,cnt+1),f(a-9,b,c-3,cnt+1));
  else if(c<=0)
    return dp[a][b][c] = min(f(a-3,b-9,c,cnt+1),f(a-9,b-3,c,cnt+1));
  
  long long ans = 9876543210;
  ans = min(ans,f(a-1,b-3,c-9,cnt+1));
  ans = min(ans,f(a-1,b-9,c-3,cnt+1));

  ans = min(ans,f(a-3,b-1,c-9,cnt+1));
  ans = min(ans,f(a-3,b-9,c-1,cnt+1));

  ans = min(ans,f(a-9,b-1,c-3,cnt+1));
  ans = min(ans,f(a-9,b-3,c-1,cnt+1));

  return dp[a][b][c] = ans;
}

void solve(){
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>arr[i];
  cout<<f(arr[0],arr[1],arr[2],0);
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