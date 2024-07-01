#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  vector<int> ans;
  for(int i=1; i<=5; i++){
    string a;
    cin>>a;
    for(int j=0; j<a.size()-2; j++){
      if(a[j]=='F'&&a[j+1]=='B'&&a[j+2]=='I'){
        ans.push_back(i);
        break;
      }
    }
  }
  if(ans.empty()) {
    cout<<"HE GOT AWAY!";
    return;
  }
  for(int i : ans) cout<<i<<' ';
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
