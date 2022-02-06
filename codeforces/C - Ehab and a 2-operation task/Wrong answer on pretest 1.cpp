/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 21:12                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1088/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3,R=8e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  cout<<1<<" "<<n<<" "<<R<<"\n";
  for(int i=1;i<=n;i++)aa[i]+=R;
   for(int i=1;i<=n;i++)
    cout<<2<<" "<<i<<" "<<aa[i]-(i-1)<<"\n";
   return 0;
}