#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

long long arr[200001];
long long inf = 1e9;
long long dp1[200001];
long long dp2[200001];
long long sum[200001];

struct line{
  long long a,b;
  double mx;
};

vector<line> st1;
vector<line> st2;

double cross(line a, line b){
  return (double)(b.b-a.b)/(a.a-b.a);
}

void add_line1(long long a, long long b){
  line temp = {a,b,-inf};
  if(st1.empty()){
    st1.push_back(temp);
    return;
  }
  while(!st1.empty()){
    line t = st1.back();
    double m = cross(t,temp);
    if(m<=t.mx) st1.pop_back();
    else break;
  }
  temp.mx = cross(st1.back(),temp);
  st1.push_back(temp);
  return;
}

void add_line2(long long a, long long b){
  line temp = {a,b,-inf};
  if(st2.empty()){
    st2.push_back(temp);
    return;
  }
  while(!st2.empty()){
    line t = st2.back();
    double m = cross(t,temp);
    if(m<=t.mx) st2.pop_back();
    else break;
  }
  temp.mx = cross(st2.back(),temp);
  st2.push_back(temp);
  return;
}

long long Find1(long long a){
  int idx = st1.size()-1;
  if(a<st1.back().mx){
    int s = 0, e = idx;
    while(s+1<e){
      int mid = (s+e)/2;
      if(a<st1[mid].mx) e = mid;
      else s = mid;
    }
    idx = s;
  }
  return st1[idx].a*a+st1[idx].b;
}

long long Find2(long long a){
  int idx = st2.size()-1;
  if(a<st2.back().mx){
    int s = 0, e = idx;
    while(s+1<e){
      int mid = (s+e)/2;
      if(a<st2[mid].mx) e = mid;
      else s = mid;
    }
    idx = s;
  }
  return st2[idx].a*a+st2[idx].b;
} 

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    sum[i]=arr[i]+sum[i-1];
  }
  long long ans = -inf;
  for(int i=1; i<=n; i++){
    add_line1(i,-sum[i-1]);
    long long res = Find1(arr[i])+sum[i-1]-i*arr[i];
    ans = max(res,ans);
  }
  for(int i=n; i>=1; i--){
    add_line2(-i,-sum[i]);
    long long res = Find2(-arr[i])+sum[i]-i*arr[i];
    ans = max(ans,res);
  }
  for(int i=1; i<=n; i++)
    ans += i*arr[i];
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
