/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2018 21:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1065/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
   long mn=n-(m*2);
  mn=max(mn,0LL);
   if(m==0)cout<<mn<<" "<<n<<endl,exit(0);
   for(long i=1;i<=n;i++)
  {
    long sm=(i*(i-1))/2;
    if(sm>=m)cout<<mn<<" "<<n-i<<endl,exit(0);
  }
  return 0;
}