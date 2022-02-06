/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2020 22:35                        
*  solution_verdict: Wrong answer on pretest 14              language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 19800 KB                             
*  problem: https://codeforces.com/contest/1305/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int dg[N+2],f,vis[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int tr)
{
  vis[node]=1;
  if(node==tr){f=1;return ;}
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node,tr);if(f)return ;
  }
  vis[node]=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;dg[u]++,dg[v]++;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  set<int>st;
  for(int i=1;i<=n;i++)
  {
    if(dg[i]==1)st.insert(i);
  }
  int cnt=0;
  while(st.size()>1)
  {
    int a=-1,b=-1;
    while(st.size())
    {
      a=*st.begin();st.erase(a);
      if(!vis[a])break;
    }
    while(st.size())
    {
      b=*st.begin();st.erase(b);
      if(!vis[b])break;
    }
    if(a==-1||b==-1)assert(0);
    //cnt++;
    //if(cnt>(n/2))assert(0);
    cout<<"? "<<a<<" "<<b<<endl;
    int c;cin>>c;
    if(c==a||c==b||dg[c]==2)cout<<"! "<<c<<endl,exit(0);
    dfs(c,-1,a);dfs(c,-1,b);vis[c]=0;
     dg[c]-=2;if(dg[c]==1)st.insert(c);
    if(dg[c]<=0)assert(0);
  }
  //assert(0);
  //if(st.size()==0)assert(0);
  //if(st.size()==1)cout<<"! "<<*st.begin()<<endl,exit(0);
  //if(st.size())
  return 0;
}