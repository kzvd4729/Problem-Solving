/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-02 09:17:53                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1251
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

/**************** 2_SAT ****************/
const int S=16000;
int Desc[S+2],Low[S+2],Tim,Stacked[S+2],Anc[S+2];
vector<int>Dir[S+2],Root;stack<int>St;
void Tarjan(int node)
{
  Desc[node]=Low[node]=++Tim;
  St.push(node);Stacked[node]=1;
  for(auto x:Dir[node])
  {
    if(!Desc[x])
    {
      Tarjan(x);
      Low[node]=min(Low[node],Low[x]);
    }
    else if(Stacked[x])
      Low[node]=min(Low[node],Low[x]);
  }
  if(Low[node]==Desc[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=St.top();St.pop();
      Stacked[now]=0;Anc[now]=node;
    }
    Root.push_back(node);
  }
}
void Strongly_Connected_Component(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(Desc[i])continue;
    Tarjan(i);
  }
}
const int T=16000;
vector<int>topo_sorted,topo[T+2];
int tp_vis[T+2];
void Topo_sort(int node)
{
  tp_vis[node]=1;
  for(auto x:topo[node])
  {
    if(tp_vis[x])continue;
    Topo_sort(x);
  }
  topo_sorted.push_back(node);
}
vector<int>Topological_Sort(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(tp_vis[i])continue;
    Topo_sort(i);
  }
  reverse(topo_sorted.begin(),topo_sorted.end());
  return topo_sorted;
}
void OR(int n,int u,int v)
{
  Dir[n+v].push_back(u);Dir[n+u].push_back(v);
}
void AND(int n,int u,int v)
{
  Dir[u].push_back(v);Dir[v].push_back(u);
}
void XOR(int n,int u,int v)
{
  Dir[n+v].push_back(u);Dir[u].push_back(n+v);
  Dir[n+u].push_back(v);Dir[v].push_back(n+u);
}
void XNOR(int n,int u,int v)
{
  Dir[u].push_back(v);Dir[v].push_back(u);
  Dir[n+v].push_back(n+u);Dir[n+u].push_back(n+v);
}
bool Two_SAT(int n,vector<int>&ans)
{
  Strongly_Connected_Component(n+n);
  for(int i=1;i<=n;i++)
    if(Anc[i]&&Anc[n+i]&&Anc[i]==Anc[n+i])return false;
  int cnt=0,cm[n+n+2];
  for(auto x:Root)
    cm[x]=++cnt;
  for(int u=1;u<=n+n;u++)
  {
    for(auto v:Dir[u])
    {
      int x=cm[Anc[u]],y=cm[Anc[v]];
      if(x==y)continue;
      topo[x].push_back(y);
    }
  }
  vector<int>tp=Topological_Sort(cnt);
  vector<int>v[n+n+2],sat;
  for(int i=1;i<=n+n;i++)
    v[cm[Anc[i]]].push_back(i);
  for(auto x:tp)
    for(auto z:v[x])
      sat.push_back(z);
  vector<int>vis(n+n+2,0);
  for(auto x:sat)
  {
    if(x>n)vis[x-n]=1;
    else if(vis[x])ans.push_back(x);
  }
  return true;
}
///////////////////////////////////////////////
void clear(int n)
{
  for(int i=1;i<=n+n;i++)
  {
    Desc[i]=0,Low[i]=0;
    Anc[i]=0;Dir[i].clear();
    Stacked[i]=0;topo[i].clear();
    tp_vis[i]=0;
  }
  while(St.size())St.pop();Root.clear();Tim=0;
  topo_sorted.clear();
}

int main()
{
  int tc=0,t;scanf("%d",&t);
  while(t--)
  {
    int n,m;scanf("%d%d",&n,&m);
    clear(m);
    while(n--)
    {
      char a[10],b[10];scanf("%s%s",a,b);
      int u=0,v=0;
      int x=strlen(a),y=strlen(b);
      for(int i=1;i<x;i++)
        u=u*10+(a[i]-'0');
      for(int i=1;i<y;i++)
        v=v*10+(b[i]-'0');
      if(a[0]=='+'&&b[0]=='+')OR(n,u,v);
      else if(a[0]=='+'&&b[0]=='-')
      {
        Dir[n+u].push_back(n+v);
        Dir[v].push_back(u);
      }
      else if(a[0]=='-'&&b[0]=='+')
      {
        Dir[u].push_back(v);
        Dir[n+v].push_back(u);
      }
      else 
      {
        Dir[u].push_back(n+v);
        Dir[v].push_back(n+u);
      }
    }
    vector<int>ans;
    if(!Two_SAT(m,ans))printf("Case %d: No\n",++tc);
    else
    {
      printf("Case %d: Yes\n",++tc);
      printf("%d",(int)ans.size());
      sort(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++)
        printf(" %d",ans[i]);
      printf("\n");
    }
  }
  return 0;
}