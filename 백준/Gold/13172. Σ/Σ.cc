#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long mod = 1e9+7;

long long gcd(long long a, long long b){
  long long res;
  if(a<b) swap(a,b);
  while(b){
    res = a%b;
    a = b;
    b = res;
  }
  return a;
}

long long pow(long long a, long long b){
  long long res=1;
  while(b){
    if(b%2==1) res = (res*a)%mod;
    a = (a*a)%mod;
    b/=2;
  }
  return res;
}

void solve(){
  int n;
  cin>>n;
  long long ans=0;
  while(n--){
    long long a,b;
    cin>>a>>b;
    long long GCD = gcd(a,b);
    a/=GCD;
    b/=GCD;
    ans = (ans+(b*pow(a,mod-2))%mod)%mod;
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