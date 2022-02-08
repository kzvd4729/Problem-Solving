/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2019 13:00:29                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.17 sec                                        memory_used: 45.6M                                
*  problem: https://www.codechef.com/OCT19A/problems/EVEDG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int col[N+2],ans;
vector<int>adj[N+2];
void solve(int n,int m)
{
  for(int i=1;i<=n;i++)col[i]=0;
  if(m%2==0)
  {
    ans=1;
    for(int i=1;i<=n;i++)col[i]=1;
    return ;
  }
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()%2)
    {
      ans=2;
      for(int j=1;j<=n;j++)
        col[j]=(i==j)?2:1;
      return ;
    }
  }
  ans=3;
  for(int i=1;i<=n;i++)
    if(adj[i].size())
      {col[i]=1,col[adj[i][0]]=2;break;}
  for(int i=1;i<=n;i++)
    if(!col[i])col[i]=3;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    solve(n,m);cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
    {
      if(i>1)cout<<" ";
      cout<<col[i];
    }
    cout<<"\n";
  }
  return 0;
}