/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2020 18:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/827/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
   vector<pair<int,int> >ed;int ans=2,lt=2,rt=m+1;
  for(int i=lt;i<=rt;i++)
    ed.push_back({1,i});
  int nd=m+2;
  while(nd<=n)
  {
    if(n-nd+1<=m)
    {
      if(n==nd)ans++;else ans+=2;
      for(int i=lt;i<=rt;i++)
      {
        ed.push_back({i,nd++});
        if(nd>n)break;
      }
    }
    else
    {
      ans+=2;
      for(int i=lt;i<=rt;i++)
        ed.push_back({i,nd++});
      lt=rt+1;rt=nd-1;
    }
  }
  cout<<ans<<"\n";
  for(auto x:ed)cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}