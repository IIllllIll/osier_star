#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long a,b;
string s;
char op='0';

void div(){
  string na="",nb="";
  bool flag = false;
  for(int i=0; i<s.size(); i++){
    if(!(s[i]>='0'&&s[i]<='9')){
      if(na.size()==0) {
        na+=s[i];
        continue;
      }
      if(op=='0'){
        op = s[i];
        flag = true;
        continue;
      }
    }
    if(!flag) na+=s[i];
    else nb+=s[i];
  }
  reverse(na.begin(),na.end());
  reverse(nb.begin(),nb.end());

  long long cnt=1;
  for(int i=0; i<na.size(); i++){
    if(na[i]=='-') a*=-1;
    else {
      a+=(na[i]-'0')*cnt;
    }
    //cout<<a<<'\n';
    cnt*=8;
  }
  cnt=1;
  for(int i=0; i<nb.size(); i++){
    if(nb[i]=='-') b*=-1;
    else b+=(nb[i]-'0')*cnt;
    cnt*=8;
  }
}

void solve(){
  cin>>s;
  div();
  long long res;
  if(op=='+') res = a+b;
  else if(op=='-') res = a-b;
  else if(op=='*') res = a*b;
  else {
    if(b==0){
      cout<<"invalid";
      return;
    }
    if((a<0)^(b<0)){
      res = a/b;
      if(abs(a)%abs(b)!=0) res--;
    }
    else
      res = a/b;
  }
  if(res<0){
    cout<<'-';
    res*=-1;
  }
  if(res==0){
    cout<<0;
    return;
  }
  string ans="";
  //cout<<a<<' '<<b<<' '<<res<<'\n';
  while(res>0){
    ans += (res%8)+'0';
    res/=8;
  }
  for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
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
