#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long mod = 1000000007;

long long num[51][51];
long long arr[51][51];
long long temp[51][51];
int n;

void time(long long a[][51],long long b[][51],int t){
  memset(temp,0,sizeof(temp));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++){
        temp[i][j] += a[i][k]*b[k][j];
        temp[i][j] %= mod;
      }
    }
  }
  if(t==0){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++)
        arr[i][j] = temp[i][j];
    }
  }
  else{
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++)
        num[i][j] = temp[i][j];
    }
  }
}

void Pow(long long d){
  while(d>0){
    if(d%2==1){
      time(num,arr,1);
    }
    time(arr,arr,0);
    d/=2;
  }
}

void solve(){
  int m;
  long long d;
  cin>>n>>m;
  for(int i=0; i<m; i++){
    int s,e;
    cin>>s>>e;
    arr[s][e] = 1;
    arr[e][s] = 1;
  }
  for(int i=1; i<=n; i++) num[i][i] = 1;
  cin>>d;
  Pow(d);
  cout<<num[1][1];
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