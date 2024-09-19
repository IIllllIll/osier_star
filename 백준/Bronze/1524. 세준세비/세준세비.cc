#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second


void solve(){
  int n,m;
  priority_queue<long long> a;
  priority_queue<long long> b;
  cin>>n>>m;
  for(int i=0; i<n; i++){
    long long c;
    cin>>c;
    a.push(c);
  }
  for(int i=0; i<m; i++){
    long long c;
    cin>>c;
    b.push(c);
  }
  while((!a.empty())&&(!b.empty())){
    if(a.top()<b.top()) a.pop();
    else if(a.top()>=b.top()) b.pop();
  }
  if(!a.empty()) cout<<"S\n";
  else if(!b.empty()) cout<<"B\n";
  else cout<<"C\n";
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int ct=1;
  cin>>ct;
  while(ct--) solve();
  return 0;
}