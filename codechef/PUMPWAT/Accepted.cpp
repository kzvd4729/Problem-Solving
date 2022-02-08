/****************************************************************************************
*  @author: kzvd4729                                         created: 21-10-2018 22:19:19                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 24.4M                                
*  problem: https://www.codechef.com/COOK99A/problems/PUMPWAT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=2e9;
int aa[N+2],dp[N+2],pd[N+2],n;
int sp[22][N+2];
void build(void)
{
  for(int i=1;i<=n;i++)
    sp[0][i]=aa[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[j][i]=sp[j-1][i];
      if((i+(1<<(j-1)))<=n)
        sp[j][i]=max(sp[j-1][i],sp[j-1][i+(1<<(j-1))]);
    }
  }
}
int qry(int lt,int rt)
{
  int df=rt-lt+1;
  int on=31-__builtin_clz(df);
  return max(sp[on][lt],sp[on][rt-(1<<on)+1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    build();
    memset(dp,0,sizeof(dp));
    memset(pd,0,sizeof(pd));
    for(int i=n;i>=1;i--)
    {
      int lo=i,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(qry(i,md)>aa[i])
          hi=md;
        else lo=md;
      }
      for(md=lo;md<=hi;md++)
      {
        if(qry(i,md)>aa[i])
          break;
      }
      if(md>hi)dp[i]=1;
      else dp[i]=dp[md]+1;
    }
    for(int i=1;i<=n;i++)
    {
      int lo=1,hi=i,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(qry(md,i)>aa[i])
          lo=md;
        else hi=md;
      }
      for(md=hi;md>=lo;md--)
      {
        if(qry(md,i)>aa[i])
          break;
      }
      if(md<lo)pd[i]=1;
      else pd[i]=pd[md]+1;
    }
//    for(int i=0;i<=n+1;i++)
//      cout<<dp[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<=n+1;i++)
//      cout<<pd[i]<<" ";
//    cout<<endl;
    int ans=inf;
    for(int i=0;i<=n;i++)
    {
      ans=min(ans,pd[i]+dp[i+1]);
    }
    cout<<ans<<endl;
  }
  return 0;
}