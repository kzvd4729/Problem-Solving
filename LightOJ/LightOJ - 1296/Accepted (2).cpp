/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-10 17:55:56                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 40                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1296
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,tc,n,dp[N+2];
int grundy(int x)
{
  for(int i=30;i>=1;i--)
  {
    int xx=(1<<i);
    if(x%xx==((1<<(i-1))-1))
      return (x/xx);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>t;
  while(t--)
  {
    cin>>n;int xxr=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      xxr^=grundy(x);
    }
    if(xxr)cout<<"Case "<<++tc<<": Alice"<<endl;
    else cout<<"Case "<<++tc<<": Bob"<<endl;
  }
  return 0;
}