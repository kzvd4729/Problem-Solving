/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2020 22:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/463/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  int ans=-1;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    if(x>m||(x==m&&y))continue;
    ans=max(ans,(100-y)%100);
  }
  cout<<ans<<endl;
  return 0;
}