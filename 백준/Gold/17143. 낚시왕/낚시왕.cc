#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>

struct shark{
  int x,y,v,d,s;
};

vector<shark> fish;
int mp[101][101];
int n,m,h;

pair<int,int> move(int idx){
  shark temp = fish[idx];
  int t = temp.v;
  int a = temp.x;
  int b = temp.y;
  int di = temp.d;
  while(t--){
    if(di==1){
      if(a==1){
        di=2;
        if(n!=1)
          a++;
      }
      else a--;
    }
    else if(di==2){
      if(a==n){
        di=1;
        if(n!=1)
          a--;
      }
      else a++;
    }
    else if(di==3){
      if(b==m){
        di=4;
        if(m!=1)
          b--;
      }
      else b++;
    }
    else if(di==4){
      if(b==1){
        di=3;
        if(m!=1)
          b++;
      }
      else b--;
    }
  }
  fish[idx].d = di;
  fish[idx].x = a;
  fish[idx].y = b;
  return {a,b};
}

void next(){
  int fool[101][101];
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++)
      fool[i][j] = 0;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(mp[i][j]==0) continue;
      pair<int,int> np = move(mp[i][j]);
      if(fool[np.first][np.second]==0) fool[np.first][np.second] = mp[i][j];
      else {
        if(fish[mp[i][j]].s>fish[fool[np.first][np.second]].s)
          fool[np.first][np.second] = mp[i][j];
      }
      mp[i][j] = 0;
    }
  }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      mp[i][j] = fool[i][j];
}

void solve(){
  int ans=0;
  cin>>n>>m>>h;
  fish.resize(h+1);
  for(int i=1; i<=h; i++){
    shark a;
    cin>>a.x>>a.y>>a.v>>a.d>>a.s;
    fish[i]=a;
    mp[a.x][a.y]=i;
  }
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(mp[j][i]==0) continue;
      ans += fish[mp[j][i]].s;
      mp[j][i]=0;
      break;
    }
    next();
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