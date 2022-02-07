/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 23:59:15                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11367
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int inf=1e9;
int aa[N+2],n,m,cp,st,ed,ds[N+2][102];
vector<pair<int,int> >adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>m)
  {
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];adj[i].clear();
    }
    while(m--)
    {
      int u,v,w;cin>>u>>v>>w;u++,v++;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    int q;cin>>q;
    while(q--)
    {
      cin>>cp>>st>>ed;st++,ed++;
      queue<pair<int,int> >q;
      for(int i=1;i<=n;i++)
        for(int j=0;j<=cp;j++)
          ds[i][j]=inf;
      for(int i=0;i<=cp;i++)
      {
        ds[st][i]=i*aa[st];
        q.push({st,i});
      }
      while(q.size())
      {
        pair<int,int>p=q.front();q.pop();
        int nd=p.first;
        for(auto x:adj[nd])
        {
          if(x.second>p.second)continue;
          if(ds[x.first][p.second-x.second]>ds[nd][p.second])
          {
            ds[x.first][p.second-x.second]=ds[nd][p.second];
            q.push({x.first,p.second-x.second});
            for(int i=1; ;i++)
            {
              if(p.second-x.second+i>cp)break;
              if(ds[x.first][p.second-x.second+i]>ds[nd][p.second]+i*aa[x.first])
              {
                ds[x.first][p.second-x.second+i]=ds[nd][p.second]+i*aa[x.first];
                q.push({x.first,p.second-x.second+i});
              }
            }
          }
        }
      }
      int mn=inf;
      for(int i=0;i<=cp;i++)mn=min(mn,ds[ed][i]);
      if(mn>=inf)cout<<"impossible"<<endl;
      else cout<<mn<<endl;
    }
  }
  return 0;
}