#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int n,m;
int mp[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int a1,b1,a2,b2;

void spread(){
  int arr[51][51];
  memset(arr,0,sizeof(arr));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mp[i][j]==0||mp[i][j]==-1) continue;
      int temp = mp[i][j]/5;
      int cnt = 0;
      for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(mp[nx][ny]==-1) continue;
        cnt++;
        arr[nx][ny]+=temp;
      }
      arr[i][j] += mp[i][j]-(temp*cnt);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mp[i][j]==-1) continue;
      mp[i][j] = arr[i][j];
    }
  }
}

void clean(){
  int temp=0;
  for(int i=b1+1; i<m; i++){
    int dust = mp[a1][i];
    swap(temp,dust);
    mp[a1][i] = dust;
  }
  for(int i=a1-1; i>=0; i--){
    int dust = mp[i][m-1];
    swap(temp,dust);
    mp[i][m-1] = dust;
  }
  for(int i=m-2; i>=0; i--){
    int dust = mp[0][i];
    swap(temp,dust);
    mp[0][i] = dust;
  }
  for(int i=1; i<a1; i++){
    int dust = mp[i][0];
    swap(temp,dust);
    mp[i][0] = dust;
  }

  temp=0;
  for(int i=b2+1; i<m; i++){
    int dust = mp[a2][i];
    swap(temp,dust);
    mp[a2][i] = dust;
  }
  for(int i=a2+1; i<n; i++){
    int dust = mp[i][m-1];
    swap(temp,dust);
    mp[i][m-1] = dust;
  }
  for(int i=m-2; i>=0; i--){
    int dust = mp[n-1][i];
    swap(temp,dust);
    mp[n-1][i] = dust;
  }
  for(int i=n-2; i>a2; i--){
    int dust = mp[i][0];
    swap(temp,dust);
    mp[i][0] = dust;
  }

}

void solve(){
  int t,ans=0;
  cin>>n>>m>>t;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>mp[i][j];
      if(mp[i][j]!=-1) continue;
      if(a1==0&&b1==0) {
        a1 = i;
        b1 = j;
      }
      else{
        a2 = i;
        b2 = j;
      }
    }
  }
  while(t--) {
    spread();
    clean();
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mp[i][j]==-1) continue;
      ans+=mp[i][j];
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