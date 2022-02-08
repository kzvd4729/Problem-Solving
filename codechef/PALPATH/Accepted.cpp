/****************************************************************************************
*  @author: kzvd4729                                         created: 21-12-2019 01:31:18                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 29M                                  
*  problem: https://www.codechef.com/problems/PALPATH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long inf=1e17;
int qd[N+2][N+2],u[N+2],v[N+2],w[N+2];char c[N+2];
long ds[N+2][N+2];
vector<int>adj[N+2],an[N+2][26];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,st,ed;cin>>n>>m>>st>>ed;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();
      for(int j=0;j<26;j++)an[i][j].clear();
      for(int j=1;j<=n;j++)ds[i][j]=inf,qd[i][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
      cin>>u[i]>>v[i]>>w[i]>>c[i];
      //cout<<u[i]<<" "<<v[i]<<" ** "<<c[i]<<endl;
      an[u[i]][c[i]-'a'].push_back(i);
      an[v[i]][c[i]-'a'].push_back(i);
      adj[u[i]].push_back(i);adj[v[i]].push_back(i);
    }
    queue<pair<int,int> >q;
    ds[st][ed]=0;q.push({st,ed});qd[st][ed]=1;
    //cout<<"here"<<endl;
    while(q.size())
    {
      pair<int,int>p=q.front();q.pop();
      //cout<<p.first<<" ** "<<p.second<<endl;
      int a=p.first,b=p.second;qd[a][b]=0;
      for(auto x:adj[a])
      {
        int p=u[x];if(p==a)p=v[x];
        for(auto y:an[b][c[x]-'a'])
        {
          int g=u[y];if(g==b)g=v[y];
          if(ds[a][b]+w[x]+w[y]<ds[p][g])
          {
            ds[p][g]=ds[a][b]+w[x]+w[y];
            if(!qd[p][g])q.push({p,g}),qd[p][g]=1;
          }
        }
      }
    }
    long ans=inf;
    for(int i=1;i<=n;i++)ans=min(ans,ds[i][i]);
    for(int i=1;i<=m;i++)
    {
      ans=min(ans,ds[u[i]][v[i]]+w[i]);
      ans=min(ans,ds[v[i]][u[i]]+w[i]);
    }
    if(ans==inf)ans=-1;
    cout<<ans<<endl;
  }
  return 0;
}