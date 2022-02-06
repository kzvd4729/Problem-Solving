/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2019 20:15                        
*  solution_verdict: Time limit exceeded on test 30          language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 132200 KB                            
*  problem: https://codeforces.com/contest/666/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3,inf=1e8;
int ds[N+2][N+2],n,dp[N+2][5];
vector<int>adj[N+2];
vector<pair<int,int> >ab[N+2];
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
    }
    sort(ab[i].begin(),ab[i].end());
    while(ab[i].size())
    {
      if(ab[i].back().first==inf)ab[i].pop_back();
      else break;
    }
  }
  int mx=0,on,tw,th,fr;
  for(int i=1;i<=n;i++)
  {
    int a=max(0,(int)ab[i].size()-450);
    for(int j=ab[i].size()-1;j>=a;j--)
    {
      int b=ab[i][j].second;if(b==i)continue;
      int c=max(0,(int)ab[b].size()-450);
      for(int k=ab[b].size()-1;k>=c;k--)
      {
        int d=ab[b][k].second;if(d==i||d==b)continue;
        for(int l=ab[d].size()-1;l>=0;l--)
        {
          int e=ab[d][l].second;if(e==i||e==b||e==d)continue;
          int now=ab[i][j].first+ab[b][k].first+ab[d][l].first;
          if(now>mx)
          {
            mx=now;on=i,tw=b,th=d,fr=e;
          }
          break;
        }
      }
    }
  }
  //cout<<mx<<endl;
  cout<<on<<" "<<tw<<" "<<th<<" "<<fr<<endl;
  return 0;
}