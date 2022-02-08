/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-08 18:15:28                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 16 ms                                           memory_used: 23680 KB                             
*  problem: https://atcoder.jp/contests/abc147/tasks/abc147_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<pair<int,int> >v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    while(x--)
    {
      int a,b;cin>>a>>b;a--;
      v[i].push_back({a,b});
    }
  }
  int ans=0;
  for(int msk=0;msk<(1<<n);msk++)
  {
    int f=0;
    for(int i=1;i<=n;i++)
    {
      if(msk&(1<<(i-1)))
      {
        for(auto x:v[i])
        {
          if(((bool)(msk&(1<<x.first)))!=x.second)f=1;
        }
      }
    }
    if(!f)ans=max(ans,__builtin_popcount(msk));
  }
  cout<<ans<<endl;
  return 0;
}