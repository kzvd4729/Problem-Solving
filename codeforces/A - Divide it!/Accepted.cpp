/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 19:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1176/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,ans=0;cin>>n;
    while(n>1)
    {
      if(n%2==0)n/=2;
      else if(n%3==0)n=2*n/3;
      else if(n%5==0)n=4*n/5;
      else {ans=-1;break;}
      ans++;
    }
    cout<<ans<<"\n";
  }
  return 0;
}