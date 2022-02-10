/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-16 20:30:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 408                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1150
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=50;
int t,tc,n,ind[26][26],_dis[26][26],man,gst,lft[N+2],rgt[N+2],dis[N+2];
char s[26],mat[26][26];
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
vector<pair<int,int> >hum;
vector<int>adj[N+2];
void _bfs(int r,int c)
{
  queue<pair<int,int> >q;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      _dis[i][j]=inf;
  _dis[r][c]=0;
  q.push({r,c});
  while(q.size())
  {
    pair<int,int>p=q.front();
    //cout<<p.first<<" "<<p.second<<endl;
    q.pop();
    for(int i=0;i<4;i++)
    {
      int uu=p.first+dr[i];
      int vv=p.second+dc[i];
      //if(uu>n||uu<1||vv>n||vv<1||mat[uu][vv]=='#'||mat[uu][vv]=='H'||_dis[uu][vv]!=inf)
      if(uu>n||uu<1||vv>n||vv<1||mat[uu][vv]=='#'||_dis[uu][vv]!=inf)
        continue;
      _dis[uu][vv]=_dis[p.first][p.second]+1;
      q.push({uu,vv});
    }
  }
}
void make_graph(int xx)
{
  for(int i=1;i<=N;i++)adj[i].clear();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(mat[i][j]!='G')continue;

      _bfs(i,j);

      for(int k=0;k<hum.size();k++)
      {
        int tmp=_dis[hum[k].first][hum[k].second];
        if(tmp*2+2<=xx)
        {
          adj[ind[i][j]].push_back(ind[hum[k].first][hum[k].second]);
          //cout<<i<<" "<<j<<" "<<hum[k].first<<" "<<hum[k].second<<endl;
        }
      }
      //cout<<i<<" "<<j<<" "<<adj[ind[i][j]].size()<<endl;
    }
  }
}
bool bfs(void)
{
  queue<int>q;
  for(int i=1;i<=gst;i++)
  {
    if(lft[i]==0)
    {
      dis[i]=0;
      q.push(i);
    }
    else dis[i]=inf;
  }
  dis[0]=inf;
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      int v=adj[u][i];
      if(dis[rgt[v]]<=dis[u]+1)continue;
      dis[rgt[v]]=dis[u]+1;
      q.push(rgt[v]);
    }
  }
  return dis[0]!=inf;
}
bool dfs(int u)
{
  if(!u)return true;
  for(int i=0;i<adj[u].size();i++)
  {
    int v=adj[u][i];
    if(dis[rgt[v]]!=dis[u]+1)continue;
    if(dfs(rgt[v]))
    {
      lft[u]=v;
      rgt[v]=u;
      return true;
    }
  }
  return false;
}
int Hopcroft(void)
{
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  int matching=0;
  while(bfs())
  {
    for(int i=1;i<=gst;i++)
    {
      if(dis[i])continue;
      if(dfs(i))matching++;
    }
  }
  return matching;
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    man=0,gst=0;
    hum.clear();
    for(int i=1;i<=n;i++)
    {
      scanf("%s",s);
      for(int j=1;j<=n;j++)
      {
        mat[i][j]=s[j-1];
        if(mat[i][j]=='G')ind[i][j]=++gst;
        if(mat[i][j]=='H')
        {
          ind[i][j]=++man;
          hum.push_back({i,j});
        }
      }
    }
    //cout<<man<<" "<<gst<<endl;
    //getchar();
//    for(auto x:hum)
//    {
//      cout<<x.first<<" "<<x.second<<endl;
//    }
    int lo=0,hi=100,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      make_graph(md);
      int tmp=Hopcroft();
      //cout<<md<<" "<<tmp<<endl;
      if(tmp>=man)hi=md;
      else lo=md;
    }
    int pr=-1;
    for(int i=lo;i<=hi;i++)
    {
      make_graph(i);
      int tmp=Hopcroft();
      if(tmp==man)
      {
        pr=i;
        break;
      }
    }
    if(pr==-1)printf("Case %d: Vuter Dol Kupokat\n",++tc);
    else printf("Case %d: %d\n",++tc,pr);
  }
  return 0;
}