#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

bool check[100000001];
long long Mod = 0x1p32;

void solve(){
  for(long long i=2; i*i<=100000000; i++){
    if(check[i]) continue;
    for(long long j=i*i; j<=100000000; j+=i) check[j] = true;
  }
  long long n,ans=1;
  cin>>n;
  for(int i=2; i<=n; i++){
    if(check[i]) continue;
    long long cnt=1;
    while(cnt*i<=n) cnt*=i;
    ans=(ans*cnt)%Mod;
  }
  cout<<ans;
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