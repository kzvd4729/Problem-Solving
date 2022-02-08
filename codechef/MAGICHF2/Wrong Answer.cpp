/****************************************************************************************
*  @author: kzvd4729                                         created: 03-11-2018 03:51:31                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/NOV18A/problems/MAGICHF2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    while(k--)
    {
      if(n==1)break;
      n=(n+1)/2;
    }
    cout<<setprecision(10)<<fixed<<1.0/(n*1.0)<<"\n";
  }
  return 0;
}