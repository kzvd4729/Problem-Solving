/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2018 17:54                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 171 ms                                          memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/740/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,arr[100002],ans,l,r,pr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  ans=1e8;
  while(m--)
  {
    cin>>l>>r;
    ans=min(ans,r-l+1);
  }
  pr=0;
   cout<<ans<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<pr<<" ";
    pr++;
    if(pr==ans)pr=0;
  }
  cout<<endl;
  return 0;
}