#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long Pow(long long a, long long n, long long mod){
  long long ans = 1;
  while(n){
    if(n%2==1){
      ans*=a;
      ans%=mod;
    }
    a = (a*a)%mod;
    n/=2;
  }
  return ans;
}

void fft(vector<long long> &v, bool inv){
  long long n = v.size();
  long long w = 3;
  long long mod = 998244353;
  long long a = Pow(w,(mod-1)/n,mod);
  if(inv) a = Pow(a,mod-2,mod);
  vector<long long> root;
  root.push_back(1);
  for(int i=1; i<n/2; i++)
    root.push_back((root[i-1]*a)%mod);

  for(int i=0; i<n; i++){
    int j=0;
    int temp = i;
    for(int k=1; k<n; k*=2){
      j*=2;
      if(temp%2==1) j++;
      temp/=2;
    }
    if(i<j) swap(v[i],v[j]);
  }

  for(int i=2; i<=n; i*=2){
    int del = n/i;
    for(int j=0; j<n; j+=i){
      for(int k=0; k<i/2; k++){
        long long even = v[j+k];
        long long odd = v[j+k+(i/2)]*root[del*k]%mod;
        v[j+k] = (even+odd)%mod;
        v[j+k+(i/2)] = (even-odd)%mod;
        if(v[j+k+(i/2)]<0) v[j+k+(i/2)]+=mod;
      }
    }
  }

  long long t = Pow(n,mod-2,mod);
  if(inv) {
    for(int i=0; i<n; i++) v[i] = (v[i]*t)%mod;
  }
}

void mul(vector<long long> &a, vector<long long> &b){
  int n = 1;
  while(n<=a.size()+a.size()+1) 
    n*=2;
  a.resize(n);
  b.resize(n);
  fft(a,false);
  fft(b,false);
  for(int i=0; i<n; i++){
    a[i] *= b[i];
  }
  fft(a,true);
}

void solve(){
  string a;
  cin>>a;
  vector<long long> v,u;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='A'){
      v.push_back(1);
      u.push_back(0);
    }
    else{
      v.push_back(0);
      u.push_back(1);
    }
  } 
  reverse(u.begin(),u.end());
  mul(v,u);
  for(int i=(a.size()); i<(a.size())*2-1; i++)
    cout<<v[i]<<'\n';
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