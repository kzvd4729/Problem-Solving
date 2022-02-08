/****************************************************************************************
*  @author: kzvd4729                                         created: 04-11-2018 12:36:50                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 14.9M                                
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
    if(n==2)
    {
      cout<<0.50000000<<endl;
      continue;
    }
    while(k--)
    {
      if(n==1)break;
      n=(n+1)/2;
    }
    cout<<setprecision(10)<<fixed<<1.0/(n*1.0)<<"\n";
  }
  return 0;
}