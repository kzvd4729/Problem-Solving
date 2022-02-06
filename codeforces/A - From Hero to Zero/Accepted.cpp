/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 16:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1175/problem/A
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
      long n,k;cin>>n>>k;
      long ans=0;
      while(n)
      {
         long m=n%k;ans+=m;n-=m;
         if(!n)break;
         if(n%k==0)n/=k,ans++;
      }
      cout<<ans<<"\n";
   }
   return 0;
}