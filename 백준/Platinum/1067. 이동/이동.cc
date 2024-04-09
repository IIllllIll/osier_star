#include<bits/stdc++.h>
using namespace std;

void fft(vector<complex<double>> &v, bool inv) {
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
    double th = (inv ? acos(-1)/k : -acos(-1)/k);
    complex<double> w(cos(th), sin(th));
    for(int i=0; i<n; i+=k*2) {
      complex<double> z(1, 0);
      for(int j=0; j<k; j++) {
        complex<double> even = v[i+j];
        complex<double> odd = v[i+j+k];
        v[i+j] = even + z*odd;
        v[i+j+k] = even - z*odd;
        z *= w;
      }
    }
  }
  if(inv)
    for(int i=0; i<n; i++) v[i] /= n;
}

vector<long long> time(vector<long long> &a, vector<long long> &b){
  vector<complex<double>> v(a.begin(),a.end());
  vector<complex<double>> u(b.begin(),b.end());
  int n = 1;
  while(n<=v.size()+u.size()+1) 
    n*=2;
  v.resize(n);
  u.resize(n);
  fft(v,false);
  fft(u,false);
  for(int i=0; i<n; i++){
    v[i] *= u[i];
  }
  fft(v,true);
  vector<long long> ans(n);
  for(int i=0; i<n; i++){
    ans[i] = round(v[i].real());
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  long long ans=0;
  cin>>n;
  vector<long long> a(n*2);
  vector<long long> b(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
    a[i+n] = a[i];
  }
  for(int i=1; i<=n; i++){
    cin>>b[n-i];
  }
  vector<long long> temp = time(a,b);
  for(int i=0; i<temp.size(); i++)
    ans = max(ans,temp[i]);
  cout<<ans;
  return 0;
}
