/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/19/2020 13:54                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17                               
*  run_time: 265 ms                                          memory_used: 64100 KB                             
*  problem: https://codeforces.com/contest/1103/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<int>adj[N+2],tree[N+2];//rooted tree
vector<int>bkadj[N+2];//edges doesn't belong to the tree(end nodes are in a chain)
 int vis[N+2],lev[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      bkadj[node].push_back(x);
      bkadj[x].push_back(node);
    }
    else
    {
      tree[node].push_back(x);
      tree[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
int n,k,mx,fd,par[N+2];
void dia(int nd,int pr,int d)
{
  if(d>mx)mx=d,fd=nd;par[nd]=pr;
  for(auto x:tree[nd])
  {
    if(x==pr)continue;
    dia(x,nd,d+1);
  }
}
vector<vector<int> >ans;
int tken[N+2];
void find(int nd,int pr)
{
  par[nd]=pr;
  for(auto x:tree[nd])
    if(x!=pr)find(x,nd);
   int lv=inf;
  for(auto x:bkadj[nd])
  {
    if(lev[x]<lev[nd]&&(lev[nd]-lev[x]+1)%3&&lev[x]<lv)lv=lev[x];
  }
  if(lv==inf||ans.size()==k)return;vector<int>p;
  int tmp=nd;
  while(tmp!=-1&&lev[tmp]>=lv)
  {
    p.push_back(tmp);tmp=par[tmp];
  }
  int f=0;
  for(int i=0;i<p.size();i++)
  {
    if(tken[p[i]]==0)
    {
      f=1;vector<int>ls;
      for(int j=i;j<p.size();j++)ls.push_back(p[j]),tken[p[j]]=1;
      for(int j=0;j<i;j++)ls.push_back(p[j]),tken[p[j]]=1;
      ans.push_back(ls);break;
    }
  }
}
void tryCatch(int r)
{
  for(int i=1;i<=n;i++)tree[i].clear(),bkadj[i].clear(),vis[i]=0,tken[i]=0;
  dfs(r,-1,0);mx=0;dia(r,-1,0);mx=0;dia(fd,-1,0);
  vector<int>v;
  while(fd!=-1)
  {
    v.push_back(fd);fd=par[fd];
  }
  if(v.size()>=n/k)
  {
    cout<<"PATH\n"<<v.size()<<'\n';
    for(auto x:v)cout<<x<<" ";
      cout<<'\n';
    exit(0);
  }
  ans.clear();find(r,-1);
  if(ans.size()==k)
  {
    cout<<"CYCLES\n";
    for(auto x:ans)
    {
      cout<<x.size()<<'\n';
      for(auto z:x)cout<<z<<" ";
        cout<<'\n';
    }
    exit(0);
  }
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  vector<int>v;
  for(int i=1;i<=n;i++)v.push_back(i);
  shuffle(v.begin(),v.end(),rng);
  for(auto x:v)tryCatch(x);
   return 0;
}