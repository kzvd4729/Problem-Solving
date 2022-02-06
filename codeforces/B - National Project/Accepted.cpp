/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2020 15:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1303/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,a,b;cin>>n>>a>>b;
    long rq=(n+1)/2;
     long cy=(rq-1)/a;
     rq-=cy*a;long ans=cy*(a+b);
    ans+=rq;
    cout<<max(ans,n)<<endl;
  }
  return 0;
}