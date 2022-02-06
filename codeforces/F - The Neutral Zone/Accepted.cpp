/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/09/2018 23:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1419 ms                                         memory_used: 12200 KB                             
*  problem: https://codeforces.com/contest/1017/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define int unsigned int
using namespace std;
bitset<100000002>bt;
int n,a,b,c,d,ans,N,sq;
void cal(int x)
{
  long xx=x;
  while(xx<=n)
  {
    ans+=(n/xx)*(a*x*x*x+b*x*x+c*x+d);
    xx*=x;
  }
}
void seive(void)
{
  cal(2);cal(3);sq=sqrt(n+1);
  for(int i=1;i<=n;i++)
  {
    if(i*6-1>n)break;
    if(!bt[2*i])
    {
      int x=i*6-1;cal(x);
      if(x<=sq)
      {
        for(int j=x*x;j<=n;j+=2*x)
        {
          if(j%6==5)
          {
            bt[((j+1)/6)*2]=1;
          }
          else if(j%6==1)
          {
            bt[((j+1)/6)*2+1]=1;
          }
        }
      }
    }
    if(i*6+1>n)break;
    if(!bt[2*i+1])
    {
      int x=i*6+1;cal(x);
      if(x<=sq)
      {
        for(int j=x*x;j<=n;j+=2*x)
        {
          if(j%6==5)
          {
            bt[((j+1)/6)*2]=1;
          }
          else if(j%6==1)
          {
            bt[((j+1)/6)*2+1]=1;
          }
        }
      }
    }
  }
}
main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b>>c>>d;
  seive();cout<<ans<<endl;
   return 0;
}