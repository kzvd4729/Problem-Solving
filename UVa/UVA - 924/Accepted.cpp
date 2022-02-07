/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-02 23:29:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-924
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int inf=1e8;
int n,m,x,dis[2505],cnt[2505],mx,day,q;
vector<int>adj[2505];
void bfs(int s)
{
  queue<int>q;
  q.push(s);
  dis[s]=0;
  cnt[0]++;
  while(q.size())
  {
    int u=q.front();
    q.pop();
    for(auto v:adj[u])
    {
      if(dis[u]+1<dis[v])
      {
        dis[v]=dis[u]+1;
        cnt[dis[v]]++;
        q.push(v);
      }
    }
  }
  mx=0,day=0;
  for(int i=1;i<n;i++)
  {
    if(cnt[i]>mx)
    {
      mx=cnt[i];
      day=i;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n)
  {
    for(int i=0;i<n;i++)
      adj[i].clear();
    for(int i=0;i<n;i++)
    {
      cin>>m;
      while(m--)
      {
        cin>>x;
        adj[i].push_back(x);
      }
    }
    cin>>q;
    while(q--)
    {
      for(int i=0;i<n;i++)
        dis[i]=inf,cnt[i]=0;
      cin>>x;
      bfs(x);
      if(mx==0)cout<<mx<<endl;
      else cout<<mx<<" "<<day<<endl;
    }
  }
  return 0;
}