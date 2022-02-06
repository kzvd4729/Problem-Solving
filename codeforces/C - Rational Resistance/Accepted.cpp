/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 20:20                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/344/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
  long ans=0,tmp;
  while(true)
  {
    if(b==1)
    {
      cout<<ans+a<<endl;
      return 0;
    }
    if(a>b)
    {
      tmp=(a-b)/b;
      ans+=tmp;
      a-=(b*tmp);
    }
    if(a>=b)
      a-=b;
    else
    {
      tmp=a;
      a=b-a;
      b=tmp;
    }
    ans++;
    //cout<<a<<" "<<b<<endl;
  }
  return 0;
}