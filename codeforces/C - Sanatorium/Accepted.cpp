/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 18:45                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/732/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,mxa,mna,mxb,mnb,mxc,mnc,mx,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
  if(b>=a&&b>=c)
  {
    mx=b;
    b=c;
    c=a;
    a=mx;
  }
  else if(c>=a&&c>=b)
  {
    mx=c;
    c=b;
    b=a;
    a=mx;
  }
  ///cout<<a<<" "<<b<<" "<<c<<endl;
  ans+=max(0LL,a-b-1);
  ans+=max(0LL,a-c-1);
  cout<<ans<<endl;
  return 0;
}