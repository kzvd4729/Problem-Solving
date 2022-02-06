/****************************************************************************************
*  @author: kzvd4729#                                        created: Feb/05/2020 16:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8200 KB                              
*  problem: https://codeforces.com/gym/101873/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3,inf=2e9;
int tt[N+2],pp[N+2],ds[N+2][N+2],qd[N+2][N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x;cin>>x;
  int n,m,t;cin>>n>>m>>t;
  for(int i=1;i<=m;i++)
  {
    int a,b;cin>>a>>b;
    adj[a].push_back(b);adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++)cin>>tt[i]>>pp[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=x;j++)ds[i][j]=inf;
  }
    queue<pair<int,int> >q;q.push({1,tt[1]});
  ds[1][tt[1]]=pp[1];qd[1][tt[1]]=1;
   while(q.size())
  {
    pair<int,int>p=q.front();q.pop();
    int u=p.first,v=p.second;qd[u][v]=0;
     if(v+tt[u]<=x&&ds[u][v]+pp[u]<ds[u][v+tt[u]])
    {
      ds[u][v+tt[u]]=ds[u][v]+pp[u];
      if(!qd[u][v+tt[u]])q.push({u,v+tt[u]}),qd[u][v+tt[u]]=1;
    }
    for(auto z:adj[u])
    {
      if(v+t+tt[z]>x)continue;
      if(ds[u][v]+pp[z]<ds[z][v+t+tt[z]])
      {
        ds[z][v+t+tt[z]]=ds[u][v]+pp[z];
        if(!qd[z][v+t+tt[z]])
        {
          q.push({z,v+t+tt[z]});qd[z][v+t+tt[z]]=1;
        }
      }
    }
  }
  if(ds[1][x]==inf)cout<<"It is a trap.\n",exit(0);
  cout<<ds[1][x]<<endl;
  return 0;
}