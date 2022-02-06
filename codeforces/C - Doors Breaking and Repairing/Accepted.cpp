/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/09/2019 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1102/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,x,y;cin>>n>>x>>y;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  if(x>y)cout<<n<<endl,exit(0);
   int cnt=0;
  for(int i=1;i<=n;i++)
    if(aa[i]<=x)cnt++;
  cout<<(cnt+1)/2<<endl;
   return 0;
}