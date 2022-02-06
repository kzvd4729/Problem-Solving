/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 20:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/379/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;int ans=0;
   int tt=a,rm=0;
  for(int i=1;i<=tt;i++)
  {
    ans++;rm++;
    if(rm>=b)rm-=b,tt++;
  }
  cout<<ans<<endl;
   return 0;
}