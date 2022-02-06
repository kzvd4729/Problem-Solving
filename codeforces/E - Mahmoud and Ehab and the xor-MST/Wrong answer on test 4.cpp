/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 17:58                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/959/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long pw[60],n,ans,now,p,nn,id;
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
    n-=now;
    p=1;
    while(now)
    {
      now/=2;
      ans+=now*p;
      p*=2;
    }
  }
  cout<<ans<<endl;
  return 0;
}