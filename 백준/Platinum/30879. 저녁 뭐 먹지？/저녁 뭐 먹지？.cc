#include<bits/stdc++.h>
using namespace std;

vector<int> v[200001];
stack<int> st;
int check[200001];
int id,num=0;
int sn[200001];

int dfs(int node){
  id++;
  check[node] = id;
  int cnt = id;
  st.push(node);
  for(int i=0; i<v[node].size(); i++){
    int next = v[node][i];
    if(check[next]==0) cnt = min(cnt,dfs(next));
    else if(sn[next]==-1) cnt = min(cnt,check[next]);
  }
  if(cnt==check[node]){
    while(1){
      int t = st.top();
      st.pop();
      sn[t] = num;
      if(t==node) break;
    }
    num++;
  }
  return cnt;
}

int Not(int a){
  if(a>100000) return a-100000;
  else return a+100000;
}

vector<pair<int,int>> query1;
vector<int> q;
int cnt;

bool f(int k){
  bool res = false;
  set<int> s;
  int idx = q[k];
  for(int i=0; i<idx; i++){
    int a = query1[i].first;
    int b = query1[i].second;
    if(a<0){
      a*=-1;
      a+=100000;
      s.insert(a);
    }
    else s.insert(a);
    if(b<0){
      b*=-1;
      b+=100000;
      s.insert(b);
    }
    else s.insert(b);
      
    int Not_a = Not(a);
    int Not_b = Not(b);
    v[Not_a].push_back(b);
    v[Not_b].push_back(a);
  }

  for(auto i=s.begin(); i!=s.end(); i++){
    int temp = *i;
    if(check[temp]==0) dfs(temp);
    if(sn[temp]==sn[Not(temp)]){
      res = true;
      break;
    }
  }
  
  for(auto i=s.begin(); i!=s.end(); i++){
    v[*i].clear();
  }
  memset(check,0,sizeof(check));
  memset(sn,-1,sizeof(sn));
  id=0,num=0;

  return res;
}

int Find(int s, int e){
  while(s+1<e){
    int mid = (s+e)/2;
    if(f(mid)) e = mid;
    else s = mid;
  }
  return e;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n,k=0;
  cin>>n;
  bool ans = false;
  set<int> s;
  memset(sn,-1,sizeof(sn));
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    if(x==1){
      int a,b;
      cin>>a>>b;
      query1.push_back({a,b});
      k++;
      if(a<0){
        a*=-1;
        a+=100000;
        s.insert(a);
      }
      else s.insert(a);
      if(b<0){
        b*=-1;
        b+=100000;
        s.insert(b);
      }
      else s.insert(b);
      int Not_a = Not(a);
      int Not_b = Not(b);
      v[Not_a].push_back(b);
      v[Not_b].push_back(a);
    }
    else {
      cnt++;
      q.push_back(k);
    }
  }

  for(auto i=s.begin(); i!=s.end(); i++){
    int temp = *i;
    if(check[temp]==0) dfs(temp);
    if(sn[temp]==sn[Not(temp)]){
      ans = true;
      break;
    }
  }
  
  for(auto i=s.begin(); i!=s.end(); i++){
    v[*i].clear();
  }
  if(!ans){
    for(int i=0; i<cnt; i++) cout<<"YES DINNER\n";
    return 0;
  }
  memset(check,0,sizeof(check));
  memset(sn,-1,sizeof(sn));
  id=0,num=0;

  int idx = Find(-1,cnt);

  for(int i=0; i<idx; i++) cout<<"YES DINNER\n";
  for(int i=0; i<cnt-idx; i++) cout<<"NO DINNER\n";
  return 0;
}