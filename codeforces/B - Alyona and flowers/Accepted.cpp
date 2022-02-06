/****************************************************************************************
*  @author: kzvd4729                                         created: May/05/2018 17:06                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/740/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,arr[102],here,ans,l,r;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   while(m--)
  {
    cin>>l>>r;
    here=0;
    for(int i=l;i<=r;i++)
      here+=arr[i];
    ans+=max(0,here);
  }
  cout<<ans<<endl;
  return 0;
}