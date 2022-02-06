/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2018 22:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1068/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m,k,l;cin>>n>>m>>k>>l;
  long tt=k+l;
  if(tt>n)cout<<-1<<endl,exit(0);
   long ans=(tt+m-1)/m;
   if(ans*m>n)cout<<-1<<endl,exit(0);
   cout<<ans<<endl;
   return 0;
}