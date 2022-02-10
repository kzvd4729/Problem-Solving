/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-13 18:37:03                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1330
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int aa[N+2],bb[N+2],vis[N+2],pth[N+2];
pair<int,int>mp[52][52];
map<pair<int,int>,int>ab;
int mt[52][52];

/******************* Max Flow Min Cut *******************/
const int Inf=1e9;
struct Edge
{
  int a,b,f,c;
};
vector<Edge>Ed;
vector<int>FlowAdj[N+2];
void addEdge(int a,int b,int c)
{
  Edge e;e={a,b,0,c};ab[{a,b}]=Ed.size();
  FlowAdj[a].push_back(Ed.size());
  Ed.push_back(e);e={b,a,0,0};
  //e={b,a,0,c}//Birectional
  FlowAdj[b].push_back(Ed.size());
  Ed.push_back(e);
}
int FlowDis[N+2],Sr,Sn,Pt[N+2];
bool FlowBFS(int n)
{
  for(int i=0;i<=n;i++)FlowDis[i]=Inf;
  queue<int>q;q.push(Sr);FlowDis[Sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(int i=0;i<FlowAdj[u].size();i++)
    {
      int x=FlowAdj[u][i];int v=Ed[x].b;
      if(FlowDis[v]==Inf&&Ed[x].f<Ed[x].c)
        FlowDis[v]=FlowDis[u]+1,q.push(v);
    }
  }
  return FlowDis[Sn]!=Inf;
}
int FlowDFS(int node,int flow)
{
  if(!flow||node==Sn)return flow;
  for( ;Pt[node]<FlowAdj[node].size();Pt[node]++)
  {
    int id=FlowAdj[node][Pt[node]];int v=Ed[id].b;
    if(FlowDis[v]!=FlowDis[node]+1)continue;
    if(int pushEd=FlowDFS(v,min(flow,Ed[id].c-Ed[id].f)))
    {
      Ed[id].f+=pushEd;Ed[id^1].f-=pushEd;
      return pushEd;
    }
  }
  return 0;
}
int Dinic(int n)
{
  int flow=0;
  while(FlowBFS(n))
  {
    memset(Pt,0,sizeof(Pt));
    while(int pushEd=FlowDFS(Sr,Inf))
      flow+=pushEd;
  }
  return flow;
}
///////////////////////////////////////////////////////////

vector<int>clr;
bool aug(int u)
{
  if(u==Sn)return true;
  vis[u]=1;clr.push_back(u);
  for(int i=0;i<FlowAdj[u].size();i++)
  {
    int id=FlowAdj[u][i];int v=Ed[id].b;
    if(vis[v]||Ed[id].f>=Ed[id].c)continue;
    pth[v]=id;if(aug(v))return true;
  }
  return false;
}
bool ck(int n,int nd)
{
  pth[nd]=ab[{Sr,nd}];
  if(aug(nd))
  {
    int u=Sn;
    while(u!=Sr)
    {
      int id=pth[u];
      Ed[id].f++;Ed[id^1].f--;
      u=Ed[id].a;
    }
    //memset(pth,0,sizeof(pth));
    for(int i=0;i<clr.size();i++)
      vis[clr[i]]=0;
    clr.clear();
    return true;
  }
  else
  {
    for(int i=0;i<clr.size();i++)
      vis[clr[i]]=0;
    clr.clear();
    return false;
  }
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;int s1=0,s2=0;
    for(int i=1;i<=n;i++)
      cin>>aa[i],s1+=aa[i];
    for(int i=1;i<=m;i++)
      cin>>bb[i],s2+=bb[i];
    int node=n;ab.clear();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        addEdge(node+1,node+2,1);
        mp[i][j]={node+1,node+2};
        node+=2;
      }
    }
    Sr=0;
    for(int i=1;i<=n;i++)
    {
      addEdge(Sr,i,aa[i]);
      for(int j=1;j<=m;j++)
      {
        addEdge(i,mp[i][j].first,1);
      }
    }
    Sn=node+m+1;
    for(int j=1;j<=m;j++)
    {
      addEdge(node+j,Sn,bb[j]);
      for(int i=1;i<=n;i++)
      {
        addEdge(mp[i][j].second,node+j,1);
      }
    }
    cout<<"Case "<<++tc<<":";
    int flow=Dinic(Sn);
    if(flow!=s1||flow!=s2)cout<<" impossible"<<endl;
    else
    {
      cout<<endl;vis[Sr]=1;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        {
          mt[i][j]=Ed[ab[mp[i][j]]].f;
          if(!mt[i][j])
          {
            Ed[ab[mp[i][j]]].c=0;
            continue;
          }
          int id=ab[{Sr,i}];Ed[id].f--;Ed[id^1].f++;
          id=ab[{i,mp[i][j].first}];Ed[id].f--;Ed[id^1].f++;
          id=ab[{node+j,Sn}];Ed[id].f--;Ed[id^1].f++;
          id=ab[{mp[i][j].second,node+j}];Ed[id].f--;Ed[id^1].f++;

          if(ck(Sn,i))mt[i][j]=0;

          if(mt[i][j])
          {
            id=ab[{Sr,i}];Ed[id].f++;Ed[id^1].f--;
            id=ab[{i,mp[i][j].first}];Ed[id].f++;Ed[id^1].f--;
            id=ab[{node+j,Sn}];Ed[id].f++;Ed[id^1].f--;
            id=ab[{mp[i][j].second,node+j}];Ed[id].f++;Ed[id^1].f--;
          }
        }
      }

      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
          cout<<mt[i][j];
        cout<<endl;
      }
    }

    for(int i=0;i<=Sn;i++)
      FlowAdj[i].clear();
    Ed.clear();
  }
  return 0;
}