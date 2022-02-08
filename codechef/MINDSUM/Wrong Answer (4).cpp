/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2018 16:25:50                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.30 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/OCT18A/problems/MINDSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long R=1e6,inf=1e12;
long dp[12];
long digitsum(long x)
{
  long ret=0;
  while(x)
  {
    ret+=x%10;x/=10;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,d,x;cin>>n>>d;x=n;
    for(long i=1;i<=9;i++)dp[i]=inf;
    for(long i=0;i<=R;i++)
    {
      while(x>9)x=digitsum(x);
      dp[x]=min(dp[x],i);
      x+=d;
    }
    long ans=0;
    for(long i=1;i<=9;i++)
    {
      if(dp[i]==inf)continue;
      n+=d*dp[i];
      while(n>9)n=digitsum(n),ans++;
      cout<<i<<" "<<ans+dp[i]<<endl;
      break;
    }
  }
  return 0;
}