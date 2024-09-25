#include<bits/stdc++.h>
using namespace std;
#define point pair<long long, long long>
#define x first
#define y second

struct node{
  node *l;
  node *r;
  node *p;
  int cnt,lm,rm,m,val;
  bool flip;
  node() : l(nullptr), r(nullptr), p(nullptr) {};
} *tree;

node *ptr[200002];
long long arr[200002];

void push(node *a){
  if(!a->flip) return;
  swap(a->l,a->r);
  swap(a->lm,a->rm);
  if(a->l) a->l->flip = !a->l->flip;
  if(a->r) a->r->flip = !a->r->flip;
  a->flip = 0;
}

void update(node *a){
  a->cnt = 1;
  if(a->l&&a->r){
    push(a->l);
    push(a->r);
    a->cnt += a->l->cnt+a->r->cnt;
    int l_sz = a->l->cnt;
    int r_sz = a->r->cnt;
    if(a->val){
      if(a->l->lm==l_sz)
        a->lm = l_sz+a->r->lm+1;
      else
        a->lm = a->l->lm;
      
      if(a->r->rm==r_sz)
        a->rm = r_sz+a->l->rm+1;
      else
        a->rm = a->r->rm;
      
      a->m = max(a->rm,a->lm);
      a->m = max(a->m,max(a->l->m,a->r->m));
      a->m = max(a->m,a->l->rm+1+a->r->lm);
    }
    else{
      a->lm = a->l->lm;
      a->rm = a->r->rm;
      a->m = max(a->lm,a->rm);
      a->m = max(a->m,max(a->r->m,a->l->m));
      a->m = max(a->m,max(a->r->lm,a->l->rm));
    }
    return;
  }
  if(a->l){
    push(a->l);
    a->cnt += a->l->cnt;
    if(!a->val){
      a->rm = 0;
      a->lm = a->l->lm;
      a->m = max(a->l->lm,max(a->l->rm,a->l->m));
    }
    else{
      a->rm = a->l->rm+1;
      if(a->l->lm!=a->l->cnt)
        a->lm = a->l->lm;
      else
        a->lm = a->l->lm+1;
      a->m = max(a->lm,max(a->rm,a->l->m));
    }
    return;
  }
  if(a->r){
    push(a->r);
    a->cnt += a->r->cnt;
    if(!a->val){
      a->rm = a->r->rm;
      a->lm = 0;
      a->m = max(a->r->lm,max(a->r->rm,a->r->m));
    }
    else{
      a->lm = a->r->lm+1;
      if(a->r->rm!=a->r->cnt)
        a->rm = a->r->rm;
      else
        a->rm = a->r->rm+1;
      a->m = max(a->r->m,max(a->rm,a->lm));
    }
    return;
  }
  a->lm = a->val;
  a->rm = a->val;
  a->m = a->val;
  return;
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
  ptr[0] = p;
  for(int i=1; i<=n; i++){
    p->r = new node;
    p->r->p = p;
    p = p->r;
    p->val = arr[i];
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
  node *a = tree;
  push(a);
  while(1){
    while(a->l&&a->l->cnt>k){
      a = a->l;
      push(a);
    }
    if(a->l) k-= a->l->cnt;
    if(!k) break;
    k--;
    a = a->r;
    push(a);
  }
  splay(a);
}

node *gather(int s, int e){
  k_th(e+1);
  node *a = tree;
  k_th(s-1);
  splay(a,tree);
  return tree->r->l;
}

void solve(){
  int n,m;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>arr[i];
  init(n);
  cin>>m;
  while(m--){
    int a;
    cin>>a;
    if(a==1){
      int s,e;
      cin>>s>>e;
      node *a = gather(s,e);
      a->flip = !a->flip;
      push(a);
    }
    else{
      int s,e;
      cin>>s>>e;
      node *a = gather(s,e);
      cout<<a->m<<'\n';
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