/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-10 22:46:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 15                                         memory_used (MB): 0.5                             
*  problem: https://vjudge.net/problem/URAL-1080
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int color[103],f,n,x;
vector<int>adj[102];
void dfs(int node,int c)
{
  if(color[node]!=-1)
  {
    if(color[node]!=c)
      f=1;
    return ;
  }
  if(color[node]==-1)
    color[node]=c;
  for(int i=0;i<adj[node].size();i++)
    dfs(adj[node][i],c^1);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
  {
    while(cin>>x)
    {
      if(!x)break;
      adj[i].push_back(x);
      adj[x].push_back(i);
    }
  }
  memset(color,-1,sizeof(color));
  dfs(1,0);
  if(f)cout<<-1<<endl;
  else
  {
    for(int i=1;i<=n;i++)cout<<color[i];
    cout<<endl;
  }
  return 0;
}