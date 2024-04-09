#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void fft(vector<complex<long double>> &v, bool inv) {
  int n = v.size();
  for(int i=1, j=0; i<n; i++) {
    int b = n/2;
    while(j >= b) {
      j -= b;
      b /= 2;
    }
    j += b;
    if(i < j) swap(v[i], v[j]);
  }
  for(int k=1; k<n; k*=2) {
    long double th = (inv ? acos(-1)/k : -acos(-1)/k);
    complex<long double> w(cos(th), sin(th));
    for(int i=0; i<n; i+=k*2) {
      complex<long double> z(1, 0);
      for(int j=0; j<k; j++) {
        complex<long double> even = v[i+j];
        complex<long double> odd = v[i+j+k];
        v[i+j] = even + z*odd;
        v[i+j+k] = even - z*odd;
        z *= w;
      }
    }
  }
  if(inv)
    for(int i=0; i<n; i++) v[i] /= n;
}

vector<long long> multiply(vector<long long> &a,vector<long long> &b,vector<long long> &ans){
  int n=1;
  while(n<max(a.size(),b.size())) n*=2;

  vector<complex<long double>> v(a.begin(),a.end());
  vector<complex<long double>> u(b.begin(),b.end());
  v.resize(n);
  u.resize(n);

  fft(v,0);
  fft(u,0);

  for(int i=0; i<n; i++){
    v[i] *= u[i];
  }
  fft(v,1);

  ans.resize(n);
  for(int i=0; i<ans.size(); i++){
    ans[i] = round(v[i].real());
  }
  return ans;
}

int mx = 2097152;

vector<long long> vv,uu,ans1,ans2,ans3,ans4;

void solve(){
  int n,m;
  cin>>n>>m;
  vector<long long> v;
  vector<long long> u;
  v.resize(mx,0);
  u.resize(mx,0);

  for(int i=0; i<=n; i++) cin>>v[i];
  for(int i=0; i<=m; i++) cin>>u[i];
  
  vv = v;
  uu = u;
  for(long long &i : vv) i &= ((1<<10)-1);
  for(long long &i : uu) i &= ((1<<10)-1);
  multiply(vv,uu,ans4);

  vv = v;
  uu = u;
  for(long long &i : vv) i>>=10;
  for(long long &i : uu) i &= ((1<<10)-1);
  multiply(vv,uu,ans3);

  vv = v;
  uu = u;
  for(long long &i : vv) i &= ((1<<10)-1);
  for(long long &i : uu) i >>= 10;
  multiply(vv,uu,ans2);

  vv = v;
  uu = u;
  for(long long &i : vv) i>>=10;
  for(long long &i : uu) i>>=10;
  multiply(vv,uu,ans1);

  long long ans=0;
  for(int i=0; i<=n+m; i++)  
    ans ^= (ans1[i]<<20)+((ans2[i]+ans3[i])<<10)+ans4[i];
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