/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2018 23:55                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 187 ms                                          memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/474/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long inf=1e17;
long aa[N+2];int dp[N+2];
long bit[N+2],btt[N+2];
void upd(int x,long vl)
{
  for( ;x>0;x-=x&-x)
    bit[x]=max(bit[x],vl);
}
long qry(long x)
{
  long mx=-inf;
  for( ;x<=N;x+=x&-x)
    mx=max(mx,bit[x]);
  return mx;
}
void _upd(int x,long vl)
{
  for( ;x>0;x-=x&-x)
    btt[x]=min(btt[x],vl);
}
long _qry(long x)
{
  long mn=inf;
  for( ;x<=N;x+=x&-x)
    mn=min(mn,btt[x]);
  return mn;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=N;i++)
  {
    bit[i]=-inf;btt[i]=inf;
  }
  long n,d;cin>>n>>d;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=n;i>=1;i--)
  {
    if(qry(1)-aa[i]<d)
    {
      dp[i]=max(dp[i],1);
    }
    else
    {
      int lo=1,hi=N,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(qry(md)-aa[i]<d)hi=md;
        else lo=md;
      }
      for(md=hi;md>=lo;md--)
        if(qry(md)-aa[i]>=d)break;
      dp[i]=max(dp[i],md+1);
    }
     if(aa[i]-_qry(1)<d)
    {
      dp[i]=max(dp[i],1);
    }
    else
    {
      int lo=1,hi=N,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(aa[i]-_qry(md)<d)hi=md;
        else lo=md;
      }
      for(md=hi;md>=lo;md--)
        if(aa[i]-_qry(md)>=d)break;
      dp[i]=max(dp[i],md+1);
    }
    upd(dp[i],aa[i]);_upd(dp[i],aa[i]);
  }
  // for(int i=1;i<=n;i++)
  //   cout<<dp[i]<<" ";
  // cout<<endl;
  int ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,dp[i]);
  cout<<ans<<endl;
  long last=1e18;ans++;
  for(int i=1;i<=n;i++)
  {
    if(dp[i]==ans-1&&abs(aa[i]-last)>=d)
    {
      cout<<i<<" ";last=aa[i];ans--;
    }
  }
  cout<<endl;
  return 0;
}