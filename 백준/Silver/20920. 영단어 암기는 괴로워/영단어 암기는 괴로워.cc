#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

bool cmp(const pair<string,int> &a,const pair<string,int> &b){
  if(a.y==b.y) {
    if(a.x.size()==b.x.size()) return a.x<b.x;
    return a.x.size()>b.x.size();
  }
  return a.y>b.y;
}

void solve(){
  int n,m;
  cin>>n>>m;
  unordered_map<string,int> mp;
  while(n--){
    string a;
    cin>>a;
    if(a.size()>=m) mp[a]++;
  }
  vector<pair<string, int>> v(mp.begin(),mp.end());
  sort(v.begin(),v.end(),cmp);
  for(int i=0; i<v.size(); i++) cout<<v[i].x<<'\n';
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