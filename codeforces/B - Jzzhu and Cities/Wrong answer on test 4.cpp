/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 00:29                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/449/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long inf=2e15;
long n,m,k,u,v,w,dis[N+2],in[N+2];
vector<pair<long,long> >adj[N+2];
void whore(void)
{
  for(long i=1;i<=n;i++)dis[i]=inf;
  queue<long>q;
  q.push(1);
  dis[1]=0;
  in[1]=1;
  while(q.size())
  {
    long u=q.front();
    q.pop();
    in[u]=0;
    for(auto x:adj[u])
    {
      if(dis[u]+x.second<dis[x.first])
      {
        dis[x.first]=dis[u]+x.second;
        if(in[x.first]==0)
        {
          q.push(x.first);
          in[x.first]=1;
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
  while(m--)
  {
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  whore();
  long ans=0;
  while(k--)
  {
    cin>>u>>w;
    if(dis[u]<=w)ans++;
  }
  cout<<ans<<endl;
  return 0;
}