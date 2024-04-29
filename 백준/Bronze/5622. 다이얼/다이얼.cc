#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

map <char,int> mp;

void solve(){
  string a;
  cin>>a;
  mp['A'] = 3;
  mp['B'] = 3;
  mp['C'] = 3;
  mp['D'] = 4;
  mp['E'] = 4;
  mp['F'] = 4;
  mp['G'] = 5;
  mp['H'] = 5;
  mp['I'] = 5;
  mp['J'] = 6;
  mp['K'] = 6;
  mp['L'] = 6;
  mp['M'] = 7;
  mp['N'] = 7;
  mp['O'] = 7;
  mp['P'] = 8;
  mp['Q'] = 8;
  mp['R'] = 8;
  mp['S'] = 8;
  mp['T'] = 9;
  mp['U'] = 9;
  mp['V'] = 9;
  mp['W'] = 10;
  mp['X'] = 10;
  mp['Y'] = 10;
  mp['Z'] = 10;
  int ans=0;
  for(char i : a) ans += mp[i];
  cout<<ans;
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