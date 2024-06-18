#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[100001];
vector<vector<int>> bucket;
int sqrt_n,n;

void update(int idx, int val){
  bucket[idx/sqrt_n].erase(lower_bound(bucket[idx/sqrt_n].begin(),bucket[idx/sqrt_n].end(),arr[idx]));
  arr[idx] = val;
  bucket[idx/sqrt_n].insert((lower_bound(bucket[idx/sqrt_n].begin(),bucket[idx/sqrt_n].end(),val)),val);
}

int Find(int l, int r, int val){
  int res = 0;
  while(l%sqrt_n!=0&&l<=r) {
    if(arr[l]>val) res++;
    l++;
  }
  while((r+1)%sqrt_n!=0&&l<=r) {
    if(arr[r]>val) res++;
    r--;
  }
  while(l<=r){
    res += bucket[l/sqrt_n].end()-upper_bound(bucket[l/sqrt_n].begin(),bucket[l/sqrt_n].end(),val);
    l+=sqrt_n;
  }
  return res;
}

void solve(){
  cin>>n;
  sqrt_n = 1000;
  bucket.resize(n/sqrt_n+1);
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    bucket[i/sqrt_n].push_back(arr[i]);
  }
  for(int i=0; i<=(n/sqrt_n); i++)
    sort(bucket[i].begin(),bucket[i].end());
  int m;
  cin>>m;
  while(m--){
    int a;
    cin>>a;
    if(a==2){
      int l,r,val;
      cin>>l>>r>>val;
      cout<<Find(l,r,val)<<'\n';
    }
    else{
      int idx,val;
      cin>>idx>>val;
      update(idx,val);
    }
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
