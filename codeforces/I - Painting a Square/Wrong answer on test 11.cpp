/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/12/2019 18:22                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102215/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
   int row=(n+m-1)/m;
   long ans=(1LL*row*(n-m));
  ans+=(n-m);
  cout<<ans<<endl;
    return 0;
}