#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int n,a,b;
  cin>>n>>a>>b;
  int na=1,nb=1;
  while(n--){
    na+=a;
    nb+=b;
    if(na==nb) nb--;
    else if(na<nb) swap(na,nb);
  }
  cout<<na<<" "<<nb<<'\n';
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
