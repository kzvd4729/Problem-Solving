/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/12/2018 20:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1066/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,r;cin>>n>>r;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int last,ans=0;
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      last=-1;ans++;
      for(int j=i;j<=min(i+r-1,n);j++)
      {
        if(aa[j])last=j;
      }
      if(last!=-1)
      {
        for(int j=max(last-r+1,1);j<=min(last+r-1,n);j++)
          vis[j]=1;
        continue;
      }
      for(int j=i;j>=max(i-r+1,1);j--)
      {
        if(aa[j])
        {
          last=j;break;
        }
      }
      if(last!=-1)
      {
        for(int j=max(last-r+1,1);j<=min(last+r-1,n);j++)
          vis[j]=1;
        continue;
      }
      cout<<-1<<endl,exit(0);
    }
  }
  cout<<ans<<endl;
  return 0;
}