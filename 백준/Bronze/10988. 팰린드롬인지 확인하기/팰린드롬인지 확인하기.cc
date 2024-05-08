#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a;
  b = a;
  reverse(b.begin(),b.end());
  if(a==b) cout<<1;
  else cout<<0;
  return 0;
}