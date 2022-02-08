/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-12 18:07:22                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 32 ms                                           memory_used: 4736 KB                              
*  problem: https://atcoder.jp/contests/abc151/tasks/abc151_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cnt[N+2],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;int ans=0;
  while(m--)
  {
    int x;string s;cin>>x>>s;
    if(s=="AC")
    {
      if(vis[x])continue;
      ans+=cnt[x];vis[x]=1;
    }
    else
    {
      cnt[x]++;
    }
  }
  int one=0;
  for(int i=1;i<=n;i++)one+=vis[i];cout<<one<<" "<<ans<<endl;
  return 0;
}