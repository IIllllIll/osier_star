#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int par[200001];

int Find(int a){
  if(par[a]==a) return a;
  else return Find(par[a]);
}

void solve(){
  int n,q;
  cin>>n>>q;
  par[1] = 1;
  for(int i=2; i<=n; i++) cin>>par[i];
  q += n-1;
  while(q--){
    int a;
    cin>>a;
    if(a==1){
      int b,c;
      cin>>b>>c;
      if(Find(b)==Find(c)) cout<<"YES\n";
      else cout<<"NO\n";
    }
    else{
      int b;
      cin>>b;
      par[b] = b;
    }
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
