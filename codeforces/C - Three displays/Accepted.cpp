/****************************************************************************************
*  @author: kzvd4729                                         created: May/31/2018 00:48                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 46 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/987/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e12;
long n,s[3003],c[3003],ans,now,cost,mn1,mn2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>s[i];
  for(int i=1;i<=n;i++)
    cin>>c[i];
  ans=inf;
  for(int i=1;i<=n;i++)
  {
    now=s[i];
    cost=c[i];
    mn1=inf,mn2=inf;
    for(int j=1;j<i;j++)
      if(s[j]<now)
        mn1=min(mn1,c[j]);
    for(int j=i+1;j<=n;j++)
      if(s[j]>now)
        mn2=min(mn2,c[j]);
    ans=min(ans,cost+mn1+mn2);
  }
  if(ans>=inf)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}