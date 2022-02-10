/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 16:37:51                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3027
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>par[N+2];
pair<int,int>get(int x)
{
  if(x!=par[x].first)
  {
    int len=par[x].second;
    par[x]=get(par[x].first);
    par[x].second+=len;
  }
  return par[x];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;char c;
    for(int i=1;i<=n;i++)par[i]={i,0};
    while(cin>>c)
    {
      if(c=='O')break;
      if(c=='E')
      {
        int x;cin>>x;
        pair<int,int>p=get(x);
        cout<<p.second<<"\n";
      }
      else
      {
        int u,v;cin>>u>>v;
        par[u]={v,(abs(u-v))%1000};
      }
    }
  }
  return 0;
}