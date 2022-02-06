/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2018 14:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1072/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m,k;cin>>n>>m>>k;
  long ans=0;
  while(true)
  {
    if(!k)break;
    ans+=(n+n)+(m-2)+(m-2);
    n-=4,m-=4;
    //ans+=(m-4*(i-1))*(n-4*(i-1))-1;
    k--;
  }
  cout<<ans<<endl;
  return 0;
}