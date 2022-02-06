/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2019 20:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2106 ms                                         memory_used: 231500 KB                            
*  problem: https://codeforces.com/contest/666/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3,inf=1e8;
int ds[N+2][N+2],n,dp[N+2][5];
vector<int>adj[N+2];
vector<pair<int,int> >ab[N+2],ba[N+2];
void spfa(int nd)
{
  for(int i=1;i<=n;i++)ds[nd][i]=inf;
  queue<int>q;q.push(nd);ds[nd][nd]=0;
  while(q.size())
  {
    int p=q.front();q.pop();
    for(auto x:adj[p])
    {
      if(ds[nd][p]+1<ds[nd][x])
      {
        ds[nd][x]=ds[nd][p]+1;
        q.push(x);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
    spfa(i);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      ab[i].push_back({ds[i][j],j});
      ba[j].push_back({ds[i][j],i});
    }
    sort(ab[i].begin(),ab[i].end());
    while(ab[i].size())
    {
      if(ab[i].back().first==inf)ab[i].pop_back();
      else break;
    }
    reverse(ab[i].begin(),ab[i].end());
  }
  for(int i=1;i<=n;i++)
  {
    sort(ba[i].begin(),ba[i].end());
    while(ba[i].size())
    {
      if(ba[i].back().first==inf)ba[i].pop_back();
      else break;
    }
    reverse(ba[i].begin(),ba[i].end());
  }
  for(int i=1;i<=n;i++)
  {
    for(auto x:ba[i])
    {
      if(x.first==inf)assert(0);
    }
  }
  int mx=0,on,tw,th,fr;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;if(ds[i][j]>=inf)continue;
      for(int k=0;k<min(5,(int)ba[i].size());k++)
      {
        if(ba[i][k].second==i||ba[i][k].second==j)continue;
        for(int l=0;l<min(5,(int)ab[j].size());l++)
        {
          if(ab[j][l].second==i||ab[j][l].second==j||ab[j][l].second==ba[i][k].second)
            continue;
          //cout<<ba[i][k].first<<" --- "<<ab[j][l].first<<endl;
          if(ds[i][j]+ba[i][k].first+ab[j][l].first>mx)
          {
            mx=ds[i][j]+ba[i][k].first+ab[j][l].first;
            on=ba[i][k].second,tw=i,th=j,fr=ab[j][l].second; 
          }
        } 
      }
    }
  }
  //cout<<mx<<endl;
  cout<<on<<" "<<tw<<" "<<th<<" "<<fr<<endl;
  return 0;
}