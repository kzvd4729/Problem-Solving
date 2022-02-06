/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2021 22:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 31100 KB                             
*  problem: https://codeforces.com/gym/102700/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=1e8;
vector<pair<int,int> >ad[N+2],rv[N+2];
 int k,d[N+2][10+2],qd[N+2][10+2],a1[N+2][10+2],a2[N+2][10+2],b1[N+2][10+2],b2[N+2][10+2];
void spfa(int n,int sr)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
      d[i][j]=inf,qd[i][j]=0;
  }
  queue<pair<int,int> >q;q.push({sr,0});qd[sr][0]=1,d[sr][0]=0;
  while(q.size())
  {
    pair<int,int>u=q.front();q.pop();qd[u.first][u.second]=0;
    for(auto x:ad[u.first])
    {
      if(d[u.first][u.second]+x.second<d[x.first][u.second])
      {
        d[x.first][u.second]=d[u.first][u.second]+x.second;
        if(!qd[x.first][u.second])q.push({x.first,u.second}),qd[x.first][u.second]=1;
      }
      if(u.second==k)continue;
      if(d[u.first][u.second]<d[x.first][u.second+1])
      {
        d[x.first][u.second+1]=d[u.first][u.second];
        if(!qd[x.first][u.second+1])q.push({x.first,u.second+1}),qd[x.first][u.second+1]=1;
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  int a,b;cin>>a>>b>>k;a++,b++;
   for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;u++,v++;
    ad[u].push_back({v,w});rv[v].push_back({u,w});
  }
  spfa(n,a);
  for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)a1[i][j]=d[i][j];
  spfa(n,b);
  for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)b1[i][j]=d[i][j];
   for(int i=1;i<=n;i++)ad[i]=rv[i];
  spfa(n,a);
  for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)a2[i][j]=d[i][j];
  spfa(n,b);
  for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)b2[i][j]=d[i][j];
   int ans=inf,id=inf;
  for(int i=1;i<=n;i++)
  {
    if(i==a||i==b)continue;
    int on=inf;
    for(int x=0;x<=k;x++)
    {
      for(int y=0;y<=k;y++)
      {
        if(x+y<=k)on=min(on,a1[i][x]+a2[i][y]);
      }
    }
    int tw=inf;
    for(int x=0;x<=k;x++)
    {
      for(int y=0;y<=k;y++)
      {
        if(x+y<=k)tw=min(tw,b1[i][x]+b2[i][y]);
      }
    }
    if(on+tw<ans)ans=on+tw,id=i;
    else if(on+tw==ans)id=min(id,i);
  }
  if(ans==inf)cout<<">:("<<endl;
  else cout<<id-1<<" "<<ans<<endl;
  return 0;
}