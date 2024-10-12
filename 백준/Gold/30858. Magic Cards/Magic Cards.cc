#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<int> v[101];
int n,k,m,t;
map<string,int> flag;

bool Find(int idx, int val){
  int f = lower_bound(v[idx].begin(),v[idx].end(),val)-v[idx].begin();
  if(v[idx][f]==val) return 1;
  else return 0;
}

void solve(){
  cin>>k>>n>>m>>t;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int a;
      cin>>a;
      v[i].push_back(a);
    }
    sort(v[i].begin(),v[i].end());
  }
  for(int i=1; i<=k; i++){
    string a = "";
    for(int j=0; j<n; j++){
      if(Find(j,i)) a+='Y';
      else a+='N';
    }
    //cout<<i<<' '<<a<<'\n';
    if(flag.find(a)==flag.end())
      flag[a] = i;
    else {
      flag[a] = -1;
    }
  }
  while(t--){
    string a;
    cin>>a;
    if(flag[a]==-1) cout<<"0\n";
    else cout<<flag[a]<<'\n';
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
