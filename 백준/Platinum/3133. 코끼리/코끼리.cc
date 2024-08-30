#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

vector<long long> vx;
vector<long long> vy;
vector<point> p;
long long mod = 1e9+7;
point tree[1201010];
long long inf = 1e10;

bool cmp(point a, point b){
  if(a.x<b.x) return true;
  else if(a.x==b.x) return a.y>b.y;
  else return false;
}

point mer(point a, point b){
  if(a.x>b.x) return a;
  if(b.x>a.x) return b;
  return {a.x,(a.y+b.y)%mod};
}

void update(int node, int s, int e, int idx, point val){
  if(idx<s||idx>e) return;
  if(idx<=s&&e<=idx) {
    tree[node] = mer(tree[node],val);
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  tree[node] = mer(tree[node*2],tree[node*2+1]);
}

point Find(int node,int s, int e, int l, int r){
  if(l>e||r<s) return {-inf,0};
  if(l<=s&&e<=r) return tree[node];
  return mer(Find(node*2,s,(s+e)/2,l,r),Find(node*2+1,(s+e)/2+1,e,l,r));
}

void solve(){
  for(int i=0; i<1200000; i++) tree[i] = {-inf,0};
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    point a;
    cin>>a.x>>a.y;
    vx.push_back(a.x);
    vy.push_back(a.y);
    p.push_back(a);
  }
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
  vx.erase(unique(vx.begin(),vx.end()),vx.end());
  vy.erase(unique(vy.begin(),vy.end()),vy.end());
  
  for(int i=0; i<n; i++){
    point a;
    a.x = (lower_bound(vx.begin(),vx.end(),p[i].x)-vx.begin())+1;
    a.y = (lower_bound(vy.begin(),vy.end(),p[i].y)-vy.begin())+1;
    p[i] = a;
  }
  sort(p.begin(),p.end(),cmp);
  update(1,0,n,0,{0,1});
  for(int i=0; i<n; i++){
    point tmp = Find(1,0,n,0,p[i].y-1);
    tmp.x++;
    update(1,0,n,p[i].y,tmp);
  }
  point ans = Find(1,0,n,0,vy.size()+1);
  cout<<ans.x<<'\n'<<ans.y;
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
