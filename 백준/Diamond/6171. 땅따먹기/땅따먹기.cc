#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

struct line{
  long long a,b;
  double m;
};

long long inf = 1e9;
pair<long long,long long> v[50101];
pair<long long,long long> arr[50101];
long long dp[50101];
vector<line> st;
int idx;

double cross(line i, line j){
  return (double)(j.b-i.b)/(i.a-j.a);
}

void add_line(long long a, long long b){
  line temp = {a,b,-inf};
  if(st.empty()){
    st.push_back(temp);
    return;
  }
  while(!st.empty()){
    line top = st.back();
    double m = cross(top,temp);
    if(m<=top.m) st.pop_back();
    else break;
  }
  temp.m = cross(st.back(),temp);
  st.push_back(temp);
  if(idx>=st.size()) idx = st.size()-1;
  return;
}

long long Find(long long a){
  while(idx<st.size()-1&&st[idx+1].m<a) idx++;
  return st[idx].a*a+st[idx].b;
}

void solve(){
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>arr[i].x>>arr[i].y;
  sort(arr,arr+n);
  int k=0;
  for(int i=0; i<n; i++){
    while(k>0&&v[k-1].y<=arr[i].y) k--;
    v[k++] = arr[i];
  }
  n = k;
  add_line(v[0].y,0);
  for(int i=0; i<n-1; i++){
    dp[i] = Find(v[i].x);
    add_line(v[i+1].y,dp[i]);
  }
  cout<<Find(v[n-1].x);
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
