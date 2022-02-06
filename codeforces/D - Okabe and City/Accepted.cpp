/****************************************************************************************
*  @author: kzvd4729#                                        created: May/30/2020 12:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 295 ms                                          memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/821/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4,inf=1e9;
vector<int>adj1[N+2],adj2[N+2];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
map<int,int>ds[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;set<pair<int,int> >st;
  for(int i=1;i<=k;i++)
  {
    int u,v;cin>>u>>v;
    adj1[u].push_back(v);
    adj2[v].push_back(u);
    ds[u][v]=inf;st.insert({u,v});
  }
  ds[n][m]=inf;
  deque<pair<int,int> >q;q.push_back({1,1});ds[1][1]=0;
  while(q.size())
  {
    pair<int,int>p=q.front();q.pop_front();
    for(int k=0;k<4;k++)
    {
      int ii=p.first+dx[k];
      int jj=p.second+dy[k];
      if(st.find({ii,jj})!=st.end())
      {
        if(ds[p.first][p.second]<ds[ii][jj])
        {
          ds[ii][jj]=ds[p.first][p.second];
          q.push_front({ii,jj});
        }
      }
    }
    pair<int,int>pp=p;
    for(int i=-2;i<=2;i++)
    {
      p={pp.first+i,pp.second};if(p.first<1||p.first>n)continue;
      for(auto x:adj1[p.first])
      {
        if(ds[pp.first][pp.second]+1<ds[p.first][x])
        {
          ds[p.first][x]=ds[pp.first][pp.second]+1;
          q.push_back({p.first,x});
        }
      }
    }
    for(int i=-2;i<=2;i++)
    {
      p={pp.first,pp.second+i};if(p.second<1||p.second>m)continue;
      for(auto x:adj2[p.second])
      {
        if(ds[pp.first][pp.second]+1<ds[x][p.second])
        {
          ds[x][p.second]=ds[pp.first][pp.second]+1;
          q.push_back({x,p.second});
        }
      }
    }
  }
  int ans=ds[n][m];
  for(auto x:st)
  {
    //cout<<x.first<<" "<<x.second<<" "<<ds[x.first][x.second]<<endl;
    if(min(abs(x.first-n),abs(x.second-m))<=1)
      ans=min(ans,ds[x.first][x.second]+1);
  }
  if(ans>=inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}