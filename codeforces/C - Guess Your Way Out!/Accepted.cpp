/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 23:48                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/507/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,h,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>h>>n;
  long next=0;
  for(long i=1;i<=h;i++)
  {
    if(!next)
    {
      long hh=h-i;
      if(n>(1LL<<hh))
      {
        ans+=(1LL<<(hh+1));
        n-=(1LL<<hh);
        next=0;
      }
      else
      {
        ans++;
        next^=1;
      }
    }
    else
    {
      long hh=h-i;
      if(n<=(1LL<<hh))
      {
        ans+=(1LL<<(hh+1));
        next=1;
      }
      else
      {
        n-=(1LL<<hh);
        ans++;
        next^=1;
      }
    }
    //cout<<ans<<" "<<next<<" "<<n<<endl;
  }
  cout<<ans<<endl;
  return 0;
}