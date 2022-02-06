/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 19:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3712 ms                                         memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/265/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
const long inf=1e14;
long n,q,vl[N+2],cl[N+2],a,b;
long dp[N+2],ans;
pair<long,long>mx1,mx2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
  for(long i=1;i<=n;i++)
    cin>>vl[i];
  for(long i=1;i<=n;i++)
    cin>>cl[i];
   while(q--)
  {
    cin>>a>>b;
    mx1={-1,0};
    mx2={-1,0};
    ans=0;
    memset(dp,0,sizeof(dp));
    for(long i=n;i>=1;i--)
    {
      long tmp1,tmp2,tmp;
       tmp1=vl[i]*b+dp[cl[i]];
      dp[cl[i]]=max(dp[cl[i]],vl[i]*a+dp[cl[i]]);
       if(mx1.first!=cl[i])
      {
        tmp2=vl[i]*b+mx1.second;
        dp[cl[i]]=max(dp[cl[i]],vl[i]*a+mx1.second);
      }
      else
      {
        tmp2=vl[i]*b+mx2.second;
        dp[cl[i]]=max(dp[cl[i]],vl[i]*a+mx2.second);
      }
      tmp=max(tmp1,tmp2);
       if(cl[i]==mx1.first)
        mx1.second=max(mx1.second,tmp);
      else if(cl[i]==mx2.first)
      {
        mx2.second=max(mx2.second,tmp);
        if(mx2.second>mx1.second)swap(mx1,mx2);
      }
      else
      {
        if(tmp>mx2.second)
          mx2={cl[i],tmp};
        if(mx2.second>mx1.second)swap(mx1,mx2);
      }
//      cout<<endl;
//      cout<<mx1.first<<" "<<mx1.second<<endl;
//      cout<<mx2.first<<" "<<mx2.second<<endl;
//      cout<<endl;
       ans=max(ans,tmp);
    }
    cout<<ans<<endl;
  }
  return 0;
}