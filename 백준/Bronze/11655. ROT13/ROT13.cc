#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  string a;
  getline(cin,a);
  for(int i=0; i<a.size(); i++){
    if(a[i]>='a'&&a[i]<='z'){
    a[i]=(a[i]+13)>'z'?a[i]-13:a[i]+13;
    }
    else if(a[i]>='A'&&a[i]<='Z'){
      a[i]=(a[i]+13)>'Z'?a[i]-13:a[i]+13;;
    }
    cout<<a[i];
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