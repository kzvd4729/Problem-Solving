/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2018 21:14                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/1016/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long a[N+2],b[N+2],n;
long case1(void)
{
  long cnt=0;long ret=0;
  for(long i=1;i<=n;i++)
  {
    ret+=(a[i]*cnt);
    cnt++;
  }
  for(long i=n;i>=1;i--)
  {
    ret+=(b[i]*cnt);
    cnt++;
  }
  return ret;
}
long case2(void)
{
  long cnt=0;long ret=0;
  for(long i=1;i<=n;i++)
  {
    if(i%2)
    {
      ret+=(a[i]*cnt);
      cnt++;
      ret+=(b[i]*cnt);
      cnt++;
    }
    else
    {
      ret+=(b[i]*cnt);
      cnt++;
      ret+=(a[i]*cnt);
      cnt++;
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
    cin>>a[i];
  for(long i=1;i<=n;i++)
    cin>>b[i];
   cout<<max(case1(),case2())<<endl;
   return 0;
}