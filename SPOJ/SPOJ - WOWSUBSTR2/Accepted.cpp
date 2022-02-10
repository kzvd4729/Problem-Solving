/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-17 00:43:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 30                                         memory_used (MB): 23.6                            
*  problem: https://vjudge.net/problem/SPOJ-WOWSUBSTR2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=100007;
const long N=1e6;
long vis[N+2],x,m,po,ans,z,t,tc,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    memset(vis,0,sizeof(vis));

    cin>>n>>m;
    po=0;
    ans=0;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      po=max(po,vis[x]);
      vis[x]=i;
      z=i-po;
      ans=(ans+(z*(z+1)/2))%mod;
    }
    cout<<"Case "<<++tc<<": "<<ans%mod<<endl;
  }
  return 0;
}