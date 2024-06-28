#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int check[500][500][26];
int mp[500][500];
int flag[500][500];

void solve(){
  int n,m,k;
  int ans=0;
  cin>>n>>m>>k;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char a;
      cin>>a;
      check[i%k][j%k][a-'A']++;
      mp[i][j] = a-'A';
    }
  }
  for(int i=0; i<k; i++){
    for(int j=0; j<k; j++){
      int mx=0,idx=0;
      for(int p=0; p<26; p++){
        if(mx<check[i][j][p]){
          mx = check[i][j][p];
          idx = p;
        }
      }
      flag[i][j] = idx;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mp[i][j]!=flag[i%k][j%k]){
        ans++;
        mp[i][j] = flag[i%k][j%k];
        
      }
    }
  }
  cout<<ans<<'\n';
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cout<<(char)(mp[i][j]+'A');
    cout<<'\n';
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
