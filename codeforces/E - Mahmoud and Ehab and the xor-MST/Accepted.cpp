/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 18:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/959/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long pw[60],n,ans,now,nn,id;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   pw[0]=1;
  for(int i=1;i<=50;i++)pw[i]=pw[i-1]*2LL;
  cin>>n;
  nn=n-1;
  id=0;
  while(nn)
  {
    ans+=pw[id];
    nn/=2;
    id++;
  }
  n-=2;
  for(int i=1;n>0;i++)
  {
    now=min(n,pw[i]);
    for(int j=1;j<=50;j++)
    {
      ans=ans+(((now+pw[j-1]-1)/pw[j])*pw[j-1]);
    }
    n-=now;
  }
  cout<<ans<<endl;
  return 0;
}