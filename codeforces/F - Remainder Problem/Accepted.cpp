/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/22/2019 23:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2058 ms                                         memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1207/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,sq=650;
int cnt[sq+2][sq+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x,y;cin>>x>>y;
      for(int i=1;i<=sq;i++)
        cnt[i][x%i]-=aa[x];
      aa[x]+=y;
      for(int i=1;i<=sq;i++)
        cnt[i][x%i]+=aa[x];
    }
    else
    {
      int x,y;cin>>x>>y;
      if(x<=sq)
        cout<<cnt[x][y]<<"\n";
      else
      {
        int ans=0;
        for(int i=0;i+y<=N;i+=x)
          ans+=aa[i+y];
        cout<<ans<<"\n";
      }
    }
  }
  return 0;
}