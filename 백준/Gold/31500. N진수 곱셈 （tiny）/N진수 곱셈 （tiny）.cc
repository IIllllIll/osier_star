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

int mx=1;
vector<long long> v1,v2,u1,u2,ans1;

vector<long long> time(vector<long long> &a, vector<long long> &b){
  v1.resize(mx,0);
  v2.resize(mx,0);
  u1.resize(mx,0);
  u2.resize(mx,0);
  vector<long long> ans(a.size()+b.size()-1,0);
  for(int i=0; i<mx; i++){
    v1[i] = a[i]&((1<<10)-1);
    v2[i] = a[i]>>10;
    u1[i] = b[i]&((1<<10)-1);
    u2[i] = b[i]>>10;
  }
  
  multiply(v1,u1,ans1);
  for(int i=0; i<ans.size(); i++)
    ans[i] += ans1[i];
  multiply(v2,u1,ans1);
  for(int i=0; i<ans.size(); i++)
    ans[i] += ans1[i]<<10;
  multiply(v1,u2,ans1);
  for(int i=0; i<ans.size(); i++)
    ans[i] += ans1[i]<<10;
  multiply(v2,u2,ans1);
  for(int i=0; i<ans.size(); i++)
    ans[i] += ans1[i]<<20;
  
  
  return ans;
}

void solve(){
  long long k;
  bool flag = false;
  
  cin>>k;
  bool sign = (k<0?1:0);
  k = abs(k);

  string a,b;
  cin>>a>>b;
  vector<long long> v;
  vector<long long> u;
  if(a[0]=='~'^b[0]=='~') flag = true;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='~') continue;
    // if(sign) 
    //   v.push_back((i%2==1?-1:1)*(a[i]-'!'));
    // else
    v.push_back((a[i]-'!'));
  }

  for(int i=0; i<b.size(); i++){
    if(b[i]=='~') continue;
    // if(sign) 
    //   u.push_back((i%2==1?-1:1)*(b[i]-'!'));
    // else
    u.push_back((b[i]-'!'));
  }
  while(mx<v.size()+u.size()) 
    mx<<=1;
  int vsize = v.size();
  int usize = u.size();
  v.resize(mx);
  u.resize(mx);

  vector<long long> cnt = time(v,u);
  vector<long long> ans;

  if(!sign){
    for(int i=vsize+usize-2; i>=0; i--){
      if(i==0){
        long long temp = cnt[i];
        while(temp>0){
          ans.push_back(temp%k);
          temp/=k;
        }
        if(ans.empty()) 
          ans.push_back(0);
        break;
      }
      ans.push_back(cnt[i]%k);
      cnt[i-1]+=cnt[i]/k;
    }

    int idx = ans.size()-1;
    while(ans[idx]==0&&idx>0){
      idx--;
      if(idx==0) break;
    }
    if(flag&&!(idx==0&&ans[0]==0)) cout<<"~";
    for(int i=idx; i>=0; i--)
      cout<<(char)(ans[i]+'!');
    
  }
  else{

    for(int i=vsize+usize-2; i>=0; i--){
      if(i==0){
        long long temp = cnt[i];
        while(temp!=0){
          if(temp>0){
            ans.push_back(temp%k);
            temp = -1*(temp/k);
          }
          else{
            long long div = (-1*temp)/k;
            if((-1*temp)%k!=0) div++;
            ans.push_back(((div*k)+temp)%k);
            temp = div;
          }
        }
        if(ans.empty()) 
          ans.push_back(0);
        break;
      }
      if(cnt[i]<0){
        long long temp = (-1*cnt[i])/k;
        if((-1*cnt[i])%k!=0) temp++;
        ans.push_back(((temp*k)+cnt[i])%k);
        cnt[i-1] += temp;
      }
      else{
        ans.push_back(cnt[i]%k);
        cnt[i-1] -= cnt[i]/k;
      }
    }

    int idx = ans.size()-1;
    while(ans[idx]==0&&idx>0){
      idx--;
      if(idx==0) break;
    }
    if(flag&&!(idx==0&&ans[0]==0)) cout<<"~";
    for(int i=idx; i>=0; i--)
      cout<<(char)(ans[i]+'!');
  }
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