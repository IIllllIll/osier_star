#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

struct node{
  node *l;
  node *r;
  node *p;
  long long cnt,mn,mx,sum,val;
  bool flip, dummy;
  node() : l(nullptr), r(nullptr), p(nullptr) {};
} *tree;

node *ptr[1010101];

void push(node *a){
  if(!a->flip) return;
  swap(a->l,a->r);
  if(a->l) a->l->flip = !a->l->flip;
  if(a->r) a->r->flip = !a->r->flip;
  a->flip = 0;
}

void update(node *a){
  a->cnt = 1;
  a->mn = a->val;
  a->mx = a->val;
  a->sum = a->val;
  if(a->l){
    a->cnt += a->l->cnt;
    a->mx = max(a->mx,a->l->mx);
    a->mn = min(a->mn,a->l->mn);
    a->sum += a->l->sum;
  }
  if(a->r){
    a->cnt += a->r->cnt;
    a->mx = max(a->mx,a->r->mx);
    a->mn = min(a->mn,a->r->mn);
    a->sum += a->r->sum;
  }
}

void Rotate(node *a){
  node *p = a->p;
  node *b;
  push(p);
  push(a);
  if(a==p->l){
    p->l = b = a->r;
    a->r = p;
  }
  else{
    p->r = b = a->l;
    a->l = p;
  }
  a->p = p->p;
  p->p = a;
  if(b) b->p = p;
  if(a->p){
    if(p==a->p->l) a->p->l = a;
    else a->p->r = a;
  }
  else tree = a;
  update(p);
  update(a);
}

void splay(node *a, node *g=nullptr){
  node *b;
  while(a->p!=g){
    node *p = a->p;
    if(p->p==g){
      Rotate(a);
      break;
    }
    node *pp = p->p;
    if(((p->l)==a)==(pp->l==p)){
      Rotate(p);
      Rotate(a);
    }
    else{
      Rotate(a);
      Rotate(a);
    }
  }
  if(!g) tree = a;
}

void init(int n){
  node *p;
  tree = p = new node;
  p->val = 0;
  p->flip = 0;
  ptr[0] = p;
  for(int i=1; i<=n; i++){
    p->r = new node;
    p->r->p = p;
    p = p->r;
    p->val = i;
    p->flip = 0;
    ptr[i] = p;
  }
  p->r = new node;
  p->r->p = p;
  p = p->r;
  p->val = 0;
  p->flip = 0;
  ptr[n+1] = p;
  while(p){
    update(p);
    p = p->p;
  }
}

void k_th(int k){
  node *now = tree;
  push(now);
  while(1){
    while(now->l&&now->l->cnt>k){
      now = now->l;
      push(now);
    }
    if(now->l) k-= now->l->cnt;
    if(!k) break;
    k--;
    now = now->r;
    push(now);
  }
  splay(now);
}

node *gather(int s, int e){
  k_th(e+1);
  node *a = tree;
  k_th(s-1);
  splay(a,tree);
  return tree->r->l;
}

void Flip(int s,int e){
  node *a = gather(s,e);
  a->flip = !a->flip;
}

void shift(int s, int e, int k){
  node *a = gather(s,e);
  cout<<a->mn<<' '<<a->mx<<' '<<a->sum<<'\n';
  if(k>=0){
    k %= (e-s+1);
    if(k==0) return;
    Flip(s,e);
    Flip(s,s+k-1);
    Flip(s+k,e);
  }
  else{
    k *= -1;
    k %= (e-s+1);
    if(k==0) return;
    Flip(s,e);
    Flip(s,e-k);
    Flip(e-k+1,e);
  }
}

void solve(){
  int n,m;
  cin>>n>>m;
  init(n);
  while(m--){
    int a;
    cin>>a;
    if(a==1){
      int s,e;
      cin>>s>>e;
      node *a = gather(s,e);
      cout<<a->mn<<' '<<a->mx<<' '<<a->sum<<'\n';
      a->flip = !a->flip;
      push(a);
    }
    else if(a==2){
      int s,e,k;
      cin>>s>>e>>k;
      shift(s,e,k);
    }
    else if(a==3){
      int idx;
      cin>>idx;
      k_th(idx);
      cout<<tree->val<<'\n';
    }
    else{
      int idx;
      cin>>idx;
      splay(ptr[idx]);
      cout<<tree->l->cnt<<'\n';
    }
  }
  for(int i=1; i<=n; i++){
    k_th(i);
    cout<<tree->val<<' ';
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