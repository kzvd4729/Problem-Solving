/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 18:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 25600 KB                             
*  problem: https://codeforces.com/gym/100803/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int uu[N+2],vv[N+2],ww[N+2],n,m,vis[N+2],par[N+2];
vector<vector<int> >vc;
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int mst()
{
  int ret=0;
  for(int i=1;i<=n;i++)par[i]=i;
  for(int i=1;i<=m;i++)
  {
    if(vis[i])continue;
    //cout<<uu[i]<<" "<<vv[i]<<endl;
    int u=get(uu[i]),v=get(vv[i]);
    if(u!=v)
    {
      par[u]=v;ret+=ww[i];
    }
  }
  return ret;
}
int spn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    vc.push_back({w,u,v});
  }
  sort(vc.begin(),vc.end());//reverse(vc.begin(),vc.end());
  for(int i=1;i<=m;i++)
  {
    uu[i]=vc[i-1][1],vv[i]=vc[i-1][2],ww[i]=vc[i-1][0];
  }
  for(int i=1;i<=n;i++)par[i]=i;
  for(int i=1;i<=m;i++)
  {
    int u=get(uu[i]),v=get(vv[i]);
    if(u!=v)
    {
      spn[i]=1;par[u]=v;
    }
  }
  int ms=mst();//cout<<ms<<endl;
   int cnt=0,cst=0,ls=0;
  for(int i=1;i<=m;i++)
  {
    if(!spn[i])continue;
    vis[i]=1;vis[ls]=0;ls=i;
    if(mst()>ms)
    {
      cnt++;cst+=ww[i];
    }
    else
    {
      int rt=get(1);int f=0;
      for(int j=2;j<=n;j++)
      {
        if(rt!=get(j)){f=1;break;}
      }
      if(f)cnt++,cst+=ww[i];
    }
  }
  cout<<cnt<<" "<<cst<<endl;
  return 0;
}