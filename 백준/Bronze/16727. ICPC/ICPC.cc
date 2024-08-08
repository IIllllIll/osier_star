#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int a,b,c,d;
  cin>>a>>b>>d>>c;
  int cnt_a=a+c,cnt_b=b+d;
  if(cnt_a>cnt_b) cout<<"Persepolis";
  else if(cnt_a<cnt_b) cout<<"Esteghlal";
  else{
    if(a==d) cout<<"Penalty";
    else if(a>d) cout<<"Esteghlal";
    else cout<<"Persepolis";
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