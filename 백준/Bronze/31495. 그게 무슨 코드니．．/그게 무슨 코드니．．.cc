#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  string a;
  getline(cin,a);
  int n = a.size();
  if(a[0]!='"'||a[n-1]!='"'){
    cout<<"CE";
    return;
  }
  if(n<=2){
    cout<<"CE";
    return;
  }
  for(int i=1; i+1<n; i++)
    cout<<a[i];
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