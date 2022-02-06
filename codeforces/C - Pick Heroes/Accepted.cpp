/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2018 00:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1056/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int aa[N+2],vis[N+2],pr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n+n;i++)
    cin>>aa[i];
  while(m--)
  {
    int u,v;cin>>u>>v;pr[u]=v;pr[v]=u;
  }
  int tr,last=n+n+1;cin>>tr;tr%=2;
  //cout<<"here"<<endl;
  for(int ii=1;ii<=n+n;ii++)
  {
    if(!tr)
    {
      cin>>last;vis[last]=1;
    }
    else
    {
      if(pr[last]&&!vis[pr[last]])
      {
        cout<<pr[last]<<endl;fflush(stdout);
        vis[pr[last]]=1;
      }
      else
      {
        int f=0;
        for(int i=1;i<=n+n;i++)
        {
          if(pr[i]&&!vis[i])
          {
            int u=i,v=pr[i];
            if(aa[v]>aa[u])swap(u,v);
            cout<<u<<endl;fflush(stdout);
            vis[u]=1;f=1;break;
          }
        }
        if(f==0)
        {
          int mx=-1,id=-1;
          for(int i=1;i<=n+n;i++)
          {
            if(vis[i])continue;
            if(aa[i]>mx)
            {
              mx=aa[i];id=i;
            }
          }
          cout<<id<<endl;fflush(stdout);
          vis[id]=1;
        }
      }
    }
    tr^=1;
  }
  return 0;
}