#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

bool check[201];

void f(int n){
  memset(check,0,sizeof(check));
  queue<pair<int,string>> q;
  q.push({1%n,"1"});
  check[1%n] = 1;
  while(!q.empty()){
    int temp = q.front().x;
    string ans = q.front().y;
    q.pop();
    if(temp==0){
      cout<<ans<<'\n';
      return;
    }
    temp = (temp*10)%n;
    if(!check[temp]){
      check[temp] = 1;
      q.push({temp,ans+"0"});
    }
    temp = (temp+1)%n;
    if(!check[temp]){
      check[temp] = 1;
      q.push({temp,ans+"1"});
    }
  }
}

void solve(){
  while(1){
    int n;
    cin>>n;
    if(n==0) break;
    f(n);
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
