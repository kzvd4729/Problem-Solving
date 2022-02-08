/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2018 16:41:38                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 1.24 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/OCT18A/problems/MINDSUM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long R=1e7,inf=1e12;
vector<long>dp[12];
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
    for(long i=1;i<10;i++)dp[i].clear();
    for(long i=0;i<=R;i++)
    {
      while(x>9)x=digitsum(x);
      dp[x].push_back(i);
      x+=d;
    }
    long ans=0,pr=inf;
    for(long i=1;i<=9;i++)
    {
      for(auto x:dp[i])
      {
        long xx=n+d*x;
        while(xx>9)xx=digitsum(xx),ans++;
        pr=min(pr,ans+x);
      }
      if(pr!=inf)
      {
        cout<<i<<" "<<pr<<endl;
        break;
      }
    }
  }
  return 0;
}