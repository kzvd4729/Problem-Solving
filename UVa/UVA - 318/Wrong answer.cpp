/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-19 12:10:51                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-318
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e12;
priority_queue<pair<long,long> >pq;
long dis[502],mx,ds,n,m,u,v,w,tc;
vector<pair<long,long> >adj[502];
pair<long,long>ans;
void dijkstra(void)
{
  for(int i=0;i<=n;i++)dis[i]=inf;
  dis[1]=0;
  while(pq.size())pq.pop();
  pq.push({0,1});
  while(pq.size())
  {
    pair<long,long>p;
    p=pq.top();
    pq.pop();
    for(auto x:adj[p.second])
    {
      ds=-p.first+x.second;
      if(ds<dis[x.first])
      {
        dis[x.first]=ds;
        pq.push({-dis[x.first],x.first});
      }
    }
  }
}
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n>>m)
  {
    if(n==0&&m==0)break;
    for(int i=0;i<=500;i++)adj[i].clear();
    while(m--)
    {
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    mx=0;
    dijkstra();
    double mx=0;
    ans={-1,-1};
    for(int i=1;i<=n;i++)
    {
      if(dis[i]*1.0>mx)
      {
        mx=dis[i]*1.0;
        ans={i,-1};
      }
    }
    long mn;
    for(int i=1;i<=n;i++)
    {
      for(auto x:adj[i])
      {
        mn=min(dis[i],dis[x.first]);
        long ab=abs(dis[i]-dis[x.first]);
        double z=mn*1.0+(x.second*1.0)/2.0+(ab*1.0)/2.0;
        if(z>mx)
        {
          mx=z;
          ans={i,x.first};
        }
      }
    }
    cout<<"System #"<<++tc<<endl;
    cout<<setprecision(1)<<fixed;
    if(ans.second==-1)cout<<"The last domino falls after "<<mx<<" seconds, at key domino "<<ans.first<<"."<<endl;
    else cout<<"The last domino falls after "<<mx<<" seconds, between key dominoes "<<ans.first<<" and "<<ans.second<<"."<<endl;
    cout<<endl;

  }
  return 0;
}