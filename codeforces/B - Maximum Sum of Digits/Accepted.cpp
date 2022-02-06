/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2018 13:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1060/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long ten[20];
long sum(long x)
{
  long ret=0;
  while(x)
  {
    ret+=x%10;
    x/=10;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;ten[0]=1;
  for(long i=1;i<=15;i++)
    ten[i]=ten[i-1]*10LL;
    long b=0,cnt=0,ans=0;
  while(true)
  {
    if((b*10LL+9)>n)break;
    b=b*10LL+9;cnt++;
  }
  for(long i=0;i<=9;i++)
  {
    long bb=i*ten[cnt]+b;
    if(bb>n)continue;
    long a=n-bb;
    long sm=sum(a)+sum(bb);
    ans=max(ans,sm);
  }
  cout<<ans<<endl;
  return 0;
}