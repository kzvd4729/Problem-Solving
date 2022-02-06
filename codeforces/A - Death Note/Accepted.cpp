/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2018 20:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1016/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,pre,ans,x;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  pre=0;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    x+=pre;
    ans=x/m;
    cout<<ans<<" ";
    pre=x-(ans*m);
  }
  cout<<endl;
  return 0;
}