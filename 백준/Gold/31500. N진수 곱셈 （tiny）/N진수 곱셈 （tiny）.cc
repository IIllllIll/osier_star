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

  long long w = 5;
  long long mod = 2281701377;
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

vector<long long> time(vector<long long> &a, vector<long long> &b){
  vector<long long> ans(a.size()+b.size()-1);
  for(int i=0; i<b.size(); i++){
    for(int j=0; j<a.size(); j++){
      if(ans[i+j]==0) ans[i+j] = b[i]*a[j];
      else ans[i+j] += b[i]*a[j];
    }
      
  }
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
  

  vector<long long> cnt = time(v,u);
  vector<long long> ans;

  if(!sign){
    for(int i=cnt.size()-1; i>=0; i--){
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

    for(int i=cnt.size()-1; i>=0; i--){
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