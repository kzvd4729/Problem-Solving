/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 16:15                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/331/problem/C3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans=1e9;
map<long,long>dp;
long dfs(long n,long cnt)
{
//  cout<<n<<endl;
//  getchar();
  if(n<0)return 0;
  if(n==0)
  {
    ans=min(ans,cnt);
    return 0;
  }
  long nn=n;
  while(nn)
  {
    long r=nn%10;
    nn/=10;
    if(r)dfs(n-r,cnt+1);
  }
  return 0;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   long n;
  cin>>n;
  dfs(n,0);
  cout<<ans<<endl;
   return 0;
}