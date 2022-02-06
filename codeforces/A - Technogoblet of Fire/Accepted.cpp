/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2019 21:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1121/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int pw[N+2],sc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>pw[i];
  for(int i=1;i<=n;i++)cin>>sc[i];
  int ans=0;
  while(k--)
  {
    int id,f=0;cin>>id;
    for(int i=1;i<=n;i++)
    {
      if(i==id)continue;
      if(sc[i]==sc[id]&&pw[i]>pw[id])f=1;
    }
    ans+=f;
  }
  cout<<ans<<endl;
  return 0;
}