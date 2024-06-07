#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  string a,name;
  float cnt;
  int ans=0,sum=0;
  for(int i=0; i<20; i++){
    cin>>name>>cnt>>a;
    int temp;
    if(a=="A+") temp = 45;
    else if(a=="A0") temp = 40;
    else if(a=="B+") temp = 35;
    else if(a=="B0") temp = 30;
    else if(a=="C+") temp = 25;
    else if(a=="C0") temp = 20;
    else if(a=="D+") temp = 15;
    else if(a=="D0") temp = 10;
    else temp = 0;
    ans += temp*((int)cnt);
    if(a!="P") sum+=((int)cnt);
  }
  if(sum!=0)
  cout<<(double)ans/sum/10;
  else cout<<0;
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
