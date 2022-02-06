/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 21:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1009/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,x,d,md,sum,tmp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
   while(m--)
  {
    cin>>x>>d;
    if(d<0)
    {
      if(n%2)
      {
        tmp=n/2;
        md=(tmp*(tmp+1))/2;
        md*=2;
      }
      else
      {
        tmp=n/2;
        tmp--;
        md=(tmp*(tmp+1))/2;
        md*=2;
        md+=tmp+1;
      }
    }
    else
      md=(n*(n-1))/2;
     sum+=n*x+d*md;
  }
  cout<<setprecision(10)<<fixed;
  cout<<(sum*1.00)/(n*1.00)<<endl;
  return 0;
}