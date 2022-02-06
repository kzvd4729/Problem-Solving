/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/10/2018 13:01                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/489/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3;
int fr[N+2];
vector<int>adj[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    memset(fr,0,sizeof(fr));
    for(auto x:adj[i])
    {
      for(auto z:adj[x])
      {
        //if(z!=i)
        //{
          fr[z]++;
        //}
      }
    }
    for(int j=1;j<=n;j++)
    {
      if(fr[j]>=2)
        ans+=(fr[j]*fr[j]-1)/2;
    }
  }
  cout<<ans<<endl;
  return 0;
}