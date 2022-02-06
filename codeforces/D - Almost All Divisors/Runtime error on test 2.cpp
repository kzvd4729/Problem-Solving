/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 22:34                        
*  solution_verdict: Runtime error on test 2                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1165/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],yes[N+2];
bool check(long x)
{
  long sq=sqrt(x+1);
  for(int i=2;i<=sq;i++)
  {
    if(x%i==0)
    {
      int on=i,tw=x/i;
      if(!yes[on])return false;
      if(!yes[tw])return false;
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    memset(yes,0,sizeof(yes));
    for(long i=1;i<=n;i++)
    {
      cin>>aa[i];yes[aa[i]]=1;
    }
    long lcm=aa[1];
    for(long i=2;i<=n;i++)
    {
      long a=lcm,b=aa[i];
      long c=(a*b)/__gcd(a,b);
      lcm=c;
    }
    if(!check(lcm))cout<<-1<<"\n";
    else
    {
      if(yes[lcm])cout<<lcm*lcm<<endl;
      else cout<<lcm<<endl;
    }
  }
  return 0;
}