#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  long long a=1,b=0;
  int k;
  cin>>k;
  for(int i=0; i<k; i++){
    long long tmp_a = b;
    long long tmp_b = a+b;
    a = tmp_a;
    b = tmp_b;
  }
  cout<<a<<' '<<b;
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
