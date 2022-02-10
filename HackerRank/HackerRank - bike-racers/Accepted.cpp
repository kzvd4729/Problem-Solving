/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-06 23:13:49                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 60                                         memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-bike-racers
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e8;
long lft[255],rgt[255],dist[255],lcnt,rcnt,N=250;
vector<long>adj[255];

long n,m,k;
struct data
{
  long x,y;
}dr[255],bk[255];

bool bfs(void)
{
  queue<long>q;
  for(long i=1;i<=N;i++)
  {
    if(lft[i]==0)
    {
      dist[i]=0;
      q.push(i);
    }
    else
    {
      dist[i]=inf;
    }
  }
  dist[0]=inf;
  while(q.size())
  {
    long u=q.front();
    q.pop();
    if(u!=0)
    {
      long len=adj[u].size();
      for(long i=0;i<len;i++)
      {
        long v=adj[u][i];
        if(dist[rgt[v]]==inf)
        {
          dist[rgt[v]]=dist[u]+1;
          q.push(rgt[v]);
        }
      }
    }
  }
  return (dist[0]!=inf);
}
bool dfs(long u)
{
  if(u!=0)
  {
    long len=adj[u].size();
    for(long i=0;i<len;i++)
    {
      long v=adj[u][i];
      if(dist[rgt[v]]==dist[u]+1)
      {
        if(dfs(rgt[v]))
        {
          rgt[v]=u;
          lft[u]=v;
          return true;
        }
      }
    }
    dist[u]=inf;
    return false;
  }
  return true;
}
long hopcroft_karp(void)
{
  long matching=0;
  memset(lft,0,sizeof(lft));
  memset(rgt,0,sizeof(rgt));
  while(bfs())
  {
    for(long i=1;i<=N;i++)
    {
      if(lft[i]==0&&dfs(i))
        matching++;
    }
  }
  return matching;
}
long distant(long i,long j)
{
  return (dr[i].x-bk[j].x)*(dr[i].x-bk[j].x)+(dr[i].y-bk[j].y)*(dr[i].y-bk[j].y);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m>>k;
//  cout<<"     "<<n<<" "<<m<<" "<<k<<endl;
  for(long i=1;i<=n;i++)
    cin>>dr[i].x>>dr[i].y;

  for(long i=1;i<=m;i++)
    cin>>bk[i].x>>bk[i].y;

  //cout<<"here  "<<distant(1LL,4LL)<<endl;

  long lo=0,hi=1e17,md;


  while(hi-lo>5)
  {
    md=(lo+hi)/2;

    //cout<<lo<<" "<<hi<<endl;

    for(long i=1;i<=250;i++)adj[i].clear();

    for(long i=1;i<=n;i++)
      for(long j=1;j<=m;j++)
        if(distant(i,j)<=md)adj[i].push_back(j);

    long tmp=hopcroft_karp();
    //cout<<lo<<" "<<hi<<" "<<tmp<<endl;

    if(tmp>=k)hi=md;
    else lo=md;
  }
  for(long kk=lo;kk<=hi;kk++)
  {
    for(long i=1;i<=250;i++)adj[i].clear();

    for(long i=1;i<=n;i++)
      for(long j=1;j<=m;j++)
        if(distant(i,j)<=kk)adj[i].push_back(j);

    if(hopcroft_karp()>=k)
    {
      cout<<kk<<endl;
      return 0;
    }
  }
  return 0;
}