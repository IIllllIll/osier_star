#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  string a;
  cin>>a;
  set<string> se;
  for(int i=0; i<a.size(); i++){
    string tmp = "";
    for(int j=i; j<a.size(); j++){
      tmp += a[j];
      se.insert(tmp);
    }
  }
  cout<<se.size();
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
