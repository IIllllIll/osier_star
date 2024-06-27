#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

int tree[401010];

void update(int node, int s, int e, int idx, int val){
  if(idx<s||idx>e) return;
  if(s==e) {
    tree[node] += val;
    return;
  }
  update(node*2,s,(s+e)/2,idx,val);
  update(node*2+1,(s+e)/2+1,e,idx,val);
  tree[node] = tree[node*2]|tree[node*2+1];
}

int Find(int node, int s, int e, int l, int r){
  if(l>e||r<s) return 0;
  if(l<=s&&e<=r) return tree[node];
  return Find(node*2,s,(s+e)/2,l,r)|Find(node*2+1,(s+e)/2+1,e,l,r);
}

void solve(){
  int n,q;
  cin>>n>>q;
  while(q--){
    char a;
    cin>>a;
    if(a=='?'){
      int l,r;
      cin>>l>>r;
      if(l<r){
        long long ans = Find(1,1,n,l,r);
        ans &= Find(1,1,n,1,l)|Find(1,1,n,r,n);
        if(ans==1) cout<<"impossible\n";
        else cout<<"possible\n";
      }
      else{
        long long ans = Find(1,1,n,r,l);
        ans &= Find(1,1,n,1,r)|Find(1,1,n,l,n);
        if(ans==1) cout<<"impossible\n";
        else cout<<"possible\n";
      }
    }
    else if(a=='+'){
      int idx;
      cin>>idx;
      update(1,1,n,idx,-1);
    }
    else{
      int idx;
      cin>>idx;
      update(1,1,n,idx,1);
    }
  }
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
