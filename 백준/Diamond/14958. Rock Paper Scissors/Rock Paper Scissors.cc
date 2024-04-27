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

vector<long long> multiply(vector<long long> &a,vector<long long> &b){
  int n=1;
  vector<long long> ans;
  while(n<a.size()+b.size()) n*=2;

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

void solve(){
  int n,m;
  cin>>n>>m;
  string a,b;
  cin>>a>>b;

  reverse(b.begin(),b.end());
  vector<long long> v,u;
  
  for(int i=0; i<n; i++){
    if(a[i]=='P') v.push_back(1);
    else v.push_back(0);
  }

  for(int i=0; i<m; i++){
    if(b[i]=='S') u.push_back(1);
    else u.push_back(0);
  }

  vector<long long> cnt1 = multiply(v,u);
  
  v.clear();
  u.clear();

  for(int i=0; i<n; i++){
    if(a[i]=='R') v.push_back(1);
    else v.push_back(0);
  }

  for(int i=0; i<m; i++){
    if(b[i]=='P') u.push_back(1);
    else u.push_back(0);
  }

  vector<long long> cnt2 = multiply(v,u);

  v.clear();
  u.clear();

  for(int i=0; i<n; i++){
    if(a[i]=='S') v.push_back(1);
    else v.push_back(0);
  }

  for(int i=0; i<m; i++){
    if(b[i]=='R') u.push_back(1);
    else u.push_back(0);
  }

  vector<long long> cnt3 = multiply(v,u);
  long long ans = 0;

  for(int i=m-1; i<n+m-1; i++)
    ans = max(ans,cnt3[i]+cnt2[i]+cnt1[i]);
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