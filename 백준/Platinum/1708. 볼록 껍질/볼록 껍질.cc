#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

point temp; // y 값이 가장 작은 점

int ccw(point a, point b, point c){
  long long res = (a.x*b.y)+(b.x*c.y)+(c.x*a.y);
  res -= (a.y*b.x)+(b.y*c.x)+(c.y*a.x);
  if(res>0) return 1;
  else if(res<0) return -1;
  else return 0;
}

long long dist(point a, point b){
  return ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
}

bool cmp(point a, point b){
  if(a.y<b.y) return true;
  else if(a.y==b.y) return a.x<b.x;
  else return false;
}

bool CCW(point a, point b){
  int res = ccw(temp,a,b);
  if(res>0) return true;
  else if(res==0) return dist(temp,a)<dist(temp,b);
  else return false;
}

vector<point> convex_hull(vector<point> &v){
  sort(v.begin(),v.end(),cmp);
  temp = v[0];
  sort(v.begin()+1,v.end(),CCW);
  vector<point> res;
  res.push_back(v[0]);
  res.push_back(v[1]);
  for(int i=2; i<v.size(); i++){
    while(res.size()>=2){
      point st = res.back(); // 기준점 맨 앞에 있는 점
      res.pop_back();
      point nd = res.back(); // 기준점 두번째 점
      if(ccw(nd,st,v[i])>0){
        res.push_back(st);
        break;
      }
    }
    res.push_back(v[i]);
  }
  return res;
}

void solve(){
  int n;
  cin>>n;
  vector<point> v;
  for(int i=0; i<n; i++){
    point a;
    cin>>a.x>>a.y;
    v.push_back(a);
  }
  v = convex_hull(v);
  cout<<v.size();
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