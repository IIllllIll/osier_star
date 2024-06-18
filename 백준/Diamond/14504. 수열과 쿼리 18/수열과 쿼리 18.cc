#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int arr[100001];
vector<int> bucket[1000];
int sqrt_n,n;

void update(int idx, int val){
  int root_val = arr[idx];
  arr[idx] = val;
  int sqrt_idx = idx/sqrt_n;
  int Find_idx = lower_bound(bucket[sqrt_idx].begin(),bucket[sqrt_idx].end(),root_val)-bucket[sqrt_idx].begin();
  bucket[sqrt_idx][Find_idx] = val;
  sort(bucket[sqrt_idx].begin(),bucket[sqrt_idx].end());
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
  sqrt_n = sqrt(n);
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
    if(a==1){
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
