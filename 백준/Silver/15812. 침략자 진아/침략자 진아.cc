#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int mp[21][21];
vector<pair<int,int>> vil;
int n,m,ans=87654321;

void Find(int a, int b, int c, int d){
  int res = 0;
  for(pair<int,int> t:vil){
    int tmp = abs(a-t.x)+abs(b-t.y);
    tmp = min(tmp,abs(c-t.x)+abs(d-t.y));
    res = max(tmp,res);
  }
  ans = min(res,ans);
}

void solve(){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char a;
      cin>>a;
      a-='0';
      mp[i][j] = a;
      if(mp[i][j]==1) vil.push_back({i,j});
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mp[i][j]==1) continue;
      for(int k=0; k<n; k++){
        for(int p=0; p<m; p++){
          if(mp[k][p]==1) continue;
          if(i==k&&j==p) continue;
          //cout<<i<<' '<<j<<' '<<k<<' '<<p<<'\n';
          Find(i,j,k,p);
        }
      }
    }
  }
  cout<<ans;
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