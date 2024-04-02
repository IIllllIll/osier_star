#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    cout<<a+b<<'\n';
  }
  return 0;
}