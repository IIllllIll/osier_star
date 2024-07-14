#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

void solve(){
  int n;
  cin>>n;
  string a;
  cin>>a;
  long long ans=0;
  vector<int> v;
  for(int i=0; i<n; i++){
    if(a[i]=='T') v.push_back(i);
  }
  stack<int> st;
  for(int i=0; i<v.size(); i++){
    st.push(v[i]);
    while(st.size()>1){
      int e = st.top();
      st.pop();
      int s = st.top();
      if((e-s-1)%2==1){
        st.push(e);
        break;
      }
      ans += (e-s);
      st.pop();
    }
  }
  if(!st.empty()){
    cout<<"-1\n";
    return;
  }
  cout<<ans<<'\n';
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