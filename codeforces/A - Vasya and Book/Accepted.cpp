/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/28/2018 20:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1082/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int inf=2e9+1;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,x,y,d;cin>>n>>x>>y>>d;int ans=inf;
    if(abs(x-y)%d==0)ans=min(ans,abs(x-y)/d);
    if((y-1)%d==0)
      ans=min(ans,(x-1+d-1)/d+(y-1)/d);
    if((n-y)%d==0)
      ans=min(ans,(n-x+d-1)/d+(n-y)/d);
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}