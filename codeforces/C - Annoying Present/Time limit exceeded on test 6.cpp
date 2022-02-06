/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 21:25                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1009/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,x,d,md,sum;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  while(m--)
  {
    cin>>x>>d;
    if(d<0)md=n/2;
    else md=1;
     for(int i=1;i<=n;i++)
      sum+=x+d*abs(i-md);
  }
  cout<<setprecision(10)<<fixed;
  cout<<(sum*1.00)/(n*1.00)<<endl;
  return 0;
}