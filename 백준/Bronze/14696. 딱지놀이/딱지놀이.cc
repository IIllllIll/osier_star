#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int ta,tb;
  int a[5] = {0};
  int b[5] = {0};
  cin>>ta;
  while(ta--){
    int tmp;
    cin>>tmp;
    a[tmp]++;
  } 
  cin>>tb;
  while(tb--){
    int tmp;
    cin>>tmp;
    b[tmp]++;
  }
  for(int i=4; i>=1; i--){
    if(a[i]>b[i]){
      cout<<"A\n";
      return;
    }
    else if(a[i]<b[i]){
      cout<<"B\n";
      return;
    }
  }
  cout<<"D\n";
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
