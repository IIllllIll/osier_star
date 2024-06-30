#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

struct line{
  long long a,b;
  double mx;
};

double cross(line &i, line &j){
  return (double)(j.b-i.b)/(i.a-j.a);
}

long long inf = 1e8;
long long arr[200001];
vector<line> st;

void add_line(long long a, long long b){
  line tmp = {a,b,-inf};
  if(st.empty()) {
    st.push_back(tmp);
    return;
  }
  while(!st.empty()){
    line t = st.back();
    if(cross(t,tmp)<=t.mx) st.pop_back();
    else break;
  }
  tmp.mx = cross(st.back(),tmp);
  st.push_back(tmp);
  return;
}

void solve(){
  int n;
  cin>>n;
  string a;
  cin>>a;
  for(int i=0; i<a.size(); i++){
    if(i==n-1) continue;
    cout<<a[i];
  }
  cout<<'\n';
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
