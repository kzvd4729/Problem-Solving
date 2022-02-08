/****************************************************************************************
*  @author: kzvd4729                                         created: 29-02-2020 21:01:01                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 15.3M                                
*  problem: https://www.codechef.com/LTIME81A/problems/SECRETMI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2,inf=1e9;
int mt[N+2][N+2],aa[N*N+2],ed[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=k;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)mt[i][j]=inf,ed[i][j]=inf;
    }
    for(int i=1;i<=m;i++)
    {
      int u,v,w;cin>>u>>v>>w;
      mt[u][v]=min(mt[u][v],w);
      mt[v][u]=min(mt[v][u],w);
      ed[u][v]=min(ed[u][v],w);
      ed[v][u]=min(ed[v][u],w);
    }
    for(int k=1;k<=n;k++)
    {
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          mt[i][j]=min(mt[i][j],mt[i][k]+mt[k][j]);
    }
    for(int i=1;i<=n;i++)mt[i][i]=0;
    /*for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
        cout<<mt[i][j]<<" ";
      cout<<endl;
    }*/
      //cout<<mt[1][3]<<endl;
    int ans=1,f=0;
    for(int i=1;i<k; )
    {
      if(mt[aa[i]][aa[i+1]]!=ed[aa[i]][aa[i+1]]){f=1;break;}
      int sm=0,id=-1;
      for(int j=i+1;j<=k;j++)
      {
        sm+=ed[aa[j-1]][aa[j]];
        if(sm>mt[aa[i]][aa[j]])break;
        //cout<<aa[i]<<" "<<aa[j]<<" "<<sm<<" ** "<<mt[aa[i]][aa[j]]<<" "<<i<<" 
            "<<j<<endl;
        if(sm==mt[aa[i]][aa[j]])id=j;
      }
      if(id==-1)assert(0);i=id;
      ans++;
      //cout<<i<<" "<<ans<<endl;
    }
    if(f)ans=-1;
    cout<<ans<<endl;
  }
  return 0;
}