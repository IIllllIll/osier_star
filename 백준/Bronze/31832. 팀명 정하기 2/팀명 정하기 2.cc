#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int n;
  vector<string> v;
  cin>>n;
  for(int i=0; i<n; i++){
    string a;
    cin>>a;
    v.push_back(a);
  }
  for(string a : v){
    int b=0,B=0,num=0;
    for(int i=0; i<a.size(); i++){
      if(a[i]>='a'&&a[i]<='z') b++;
      else if(a[i]>='A'&&a[i]<='Z') B++;
      else if(a[i]>='0'&&a[i]<='9') num++;
    }
    if(num==a.size()) continue;
    if(a.size()>10) continue;
    if(B>b) continue;
    cout<<a;
    return; 
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
