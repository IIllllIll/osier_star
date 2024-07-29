#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int l,o,v,e;

int score(string a){
  int tl=l,to=o,tv=v,te=e;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='L') tl++;
    else if(a[i]=='O') to++;
    else if(a[i]=='V') tv++;
    else if(a[i]=='E') te++;
  }
  return ((tl+to)*(tl+tv)*(tl+te)*(to+tv)*(to+te)*(tv+te))%100;
}

bool cmp(string a, string b){
  if(score(a)>score(b)) return true;
  else if(score(a)==score(b)) return a<b;
  else return false;
}

void solve(){
  string a;
  cin>>a;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='L') l++;
    else if(a[i]=='O') o++;
    else if(a[i]=='V') v++;
    else if(a[i]=='E') e++;
  }
  int n;
  cin>>n;
  vector<string> v;
  for(int i=0; i<n; i++){
    string b;
    cin>>b;
    v.push_back(b);
  }
  sort(v.begin(),v.end(),cmp);
  cout<<v[0];
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
