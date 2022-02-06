/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1020/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e9;
const long N=2e5;
long n,h,a,b,k,ta,tb,fa,fb;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>h>>a>>b>>k;
  while(k--)
  {
    cin>>ta>>fa>>tb>>fb;
    if(ta==tb)
    {
      cout<<abs(fa-fb)<<"\n";
      continue;
    }
    long ans=0;
    if(fa<a)
    {
      ans+=a-fa;
      fa=a;
    }
    else if(fa>b)
    {
      ans+=fa-b;
      fa=b;
    }
    ans+=abs(ta-tb);
    ans+=abs(fa-fb);
    cout<<ans<<"\n";
  }
  return 0;
}