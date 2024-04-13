#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long arr[1000001];
vector<long long> v;
long long tree[1000001];
int n;

void update(int idx){
  while(idx<n){
    tree[idx]++;
    idx+=(-idx)&idx;
  }
}

long long Find(int idx){
  long long res=0;
  while(idx>0){
    res+=tree[idx];
    idx-=(-idx)&idx;
  }
  return res;
}

int f(long long &k,vector<long long> &v){
  int s=-1,e=v.size();
  while(s+1<e){
    int mid = (s+e)/2;
    if(v[mid]<k) s= mid;
    else e = mid; 
  }
  return e;
}

void solve(){
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    v.push_back(arr[i]);
  }
  sort(v.begin(),v.end());
  for(int i=1; i<=n; i++){
    int idx = f(arr[i],v)+1;
    cout<<Find(idx-1)<<'\n';
    update(idx);
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