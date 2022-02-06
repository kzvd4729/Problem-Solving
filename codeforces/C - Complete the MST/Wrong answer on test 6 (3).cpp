/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2021 20:42                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17 (64)                          
*  run_time: 248 ms                                          memory_used: 170500 KB                            
*  problem: https://codeforces.com/contest/1508/problem/C
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
  int lev[N+2],sp[N+2][21],sm[N+2];
vector<pair<int,int> >adj[N+2];
void reckon(int n,int p,int h,int s)
{
  sp[n][0]=p;lev[n]=h;sm[n]=s;
  for(auto x:adj[n])
  {
    if(x.first==p)continue;
    reckon(x.first,n,h+1,s+x.second);
  }
}
void sparse(int n)
{
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(sp[i][j-1]!=-1)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v)
{
  if(lev[u]<lev[v])swap(u,v);
  for(int i=20;i>=0;i--)
  {
    if(lev[u]-(1<<i)>=lev[v])
      u=sp[u][i];
  }
  if(u==v)return u;
  for(int i=20;i>=0;i--)
  {
    if(sp[u][i]==sp[v][i])continue;
    u=sp[u][i],v=sp[v][i];
  }
  return sp[u][0];
}
  int par[N+2];
vector<int>ad[N+2];
 int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   vector<vector<int> >ed;int xx=0;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;xx^=w;
     ad[u].push_back(v);ad[v].push_back(u);
    ed.push_back({w,u,v});
  }
   for(int i=1;i<=n;i++)sort(ad[i].begin(),ad[i].end());
   for(int i=1;i<=n;i++)par[i]=i;
   set<int>st;
  for(int i=1;i<=n;i++)st.insert(i);
  stack<int>q;
   int edge=0;
  while((int)st.size())
  {
    int b=*st.begin();st.erase(b);
    q.push(b);
     while((int)q.size())
    {
      int u=q.top();q.pop();
       vector<int>del;
      for(auto x:st)
      {
        if(binary_search(ad[u].begin(),ad[u].end(),x))continue;
         del.push_back(x);
        int r1=get(u),r2=get(x);if(r1==r2)assert(0);
        par[r1]=r2;edge++;
        adj[u].push_back({x,1});
        adj[x].push_back({u,1});
      }
      for(auto x:del)st.erase(x),q.push(x);
    }
  }
  long bad=(1LL*n*(n-1))/2-m;
  long sp=0,mx=0;
  if(bad==edge)sp=xx,mx=xx;
    sort(ed.begin(),ed.end());
   vector<vector<int> >ex;
   for(auto x:ed)
  {
    int r1=get(x[1]),r2=get(x[2]);
    if(r1==r2)
    {
      ex.push_back(x);continue;
    }
     sp+=x[0];
    par[r1]=r2;edge++;
   }
  reckon(1,0,0,0);sparse(n);
  for(auto x:ex)
  {
    if(x[0]>=mx)break;
     int lc=lca(x[1],x[2]);
    if(sm[x[1]]+sm[x[2]]-2*sm[lc]>0)
    {
      sp-=mx;sp+=x[0];break;
    }
  }
  if(edge!=n-1)assert(0);
  cout<<sp<<endl;
   return 0;
}