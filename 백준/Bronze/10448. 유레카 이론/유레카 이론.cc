#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

bool check[1001];
vector<int> v;

void solve(){
  int n;
  cin>>n;
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v.size(); j++){
      if(v[i]+v[j]>=n) break;
      if(check[n-v[i]-v[j]]) {
        cout<<"1\n";
        return;
      }
    }
  }
  cout<<"0\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int idx=1;
  while(1){
    int res = idx*(idx+1)/2;
    if(res>1000) break;
    check[res] = 1;
    v.push_back(res);
    idx++;
  }

  int ct=1;
  cin>>ct;
  while(ct--) solve();
  return 0;
}