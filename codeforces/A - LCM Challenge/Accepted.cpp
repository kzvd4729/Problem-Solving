/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2019 16:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/235/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;long mx=0;
  for(int i=n;i>=max(1,n-100);i--)
  {
    for(int j=n;j>=max(1,n-100);j--)
    {
      for(int k=n;k>=max(1,n-100);k--)
      {
        long lc1=((i*1LL)*j)/__gcd(i,j);
        long lcm=(lc1*k)/__gcd(lc1,k*1LL);
        mx=max(mx,lcm);
      }
    }
  }
  cout<<mx<<endl;
  return 0;
}