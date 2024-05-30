#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  string s;
  while(!cin.eof()){
    getline(cin,s);
    if(s.size()<1) return;
    int a=0,b=0,c=0,d=0;
    for(int i=0; s[i]!='\0'; i++){
      if(s[i]>='a'&&s[i]<='z') a++;
      else if(s[i]>='A'&&s[i]<='Z') b++;
      else if(s[i]>='0'&&s[i]<='9') c++;
      else d++;
    }
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
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
