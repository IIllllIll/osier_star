#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int n;
  cin>>n;
  if(n==1){
    cout<<"11\nA B C D E F G H J L M";
  }
  else if(n==2||n==3){
    cout<<"9\nA C E F G H I L M";
  }
  else if(n==4){
    cout<<"9\nA B C E F G H L M";
  }
  else if(5<=n&&n<=9){
    cout<<"8\nA C E F G H L M";
  }
  else{
    cout<<"8\nA B C F G H L M";
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int ct=1;
  //cin>>ct;
  while(ct--) solve();
  return 0;
}
