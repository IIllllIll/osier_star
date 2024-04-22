#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int n,m;
int mp[9][9];
int arr[9][9];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void copy(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      arr[i][j] = mp[i][j];
  }
}

int bfs(){
  queue<pair<int,int>> q;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j]==2) q.push({i,j});
    }
  }
  
  while(!q.empty()){
    int ax = q.front().x;
    int ay = q.front().y;
    q.pop();
    for(int i=0; i<4; i++){
      int nx = dx[i]+ax;
      int ny = dy[i]+ay;

      if(nx<0||nx>=n||ny<0||ny>=m) continue;
      if(arr[nx][ny]!=0) continue;
      arr[nx][ny]=2;
      q.push({nx,ny});
    }
  }

  int res=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j]==0) res++;
    }
  }

  return res;
}

void solve(){
  cin>>n>>m;
  int ans=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cin>>mp[i][j];
  }
  for(int i=0; i<n*m; i++){
    if(mp[i/m][i%m]!=0) continue;

    for(int j=i+1; j<n*m; j++){
      if(mp[j/m][j%m]!=0) continue;

      for(int k=j+1; k<n*m; k++){
        if(mp[k/m][k%m]!=0) continue;
        
        mp[i/m][i%m] = 1;
        mp[j/m][j%m] = 1;
        mp[k/m][k%m] = 1;
        copy();
        ans = max(ans,bfs());
        mp[i/m][i%m] = 0;
        mp[j/m][j%m] = 0;
        mp[k/m][k%m] = 0;

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