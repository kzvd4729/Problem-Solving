/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2021 22:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1473/problem/C
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
    int n,k;cin>>n>>k;
    int ord=k+k-1-n;
     for(int i=1;i<=ord;i++)cout<<i<<" ";
    for(int i=k;i>ord;i--)cout<<i<<" ";
      cout<<endl;
  }
  return 0;
}