/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2020 19:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 86500 KB                             
*  problem: https://codeforces.com/contest/1340/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e16;
long ds[10000+4][1000+2];
int lgh[N+2],aa[N+2],id,g,r;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    if(lgh[x]==0)lgh[x]=1,aa[++id]=x;
  }
  sort(aa+1,aa+id+1);cin>>g>>r;
   deque<pair<int,int> >q;q.push_back({1,0});
  for(int i=1;i<=m;i++)for(int j=0;j<=g;j++)ds[i][j]=inf;
  ds[1][0]=0;
   while(q.size())
  {
    pair<int,int>p=q.front();q.pop_front();
    //cout<<p.first<<" "<<p.second<<endl;
    if(p.first<id)
    {
      int ad=aa[p.first+1]-aa[p.first];
      if(p.second+ad==g)
      {
        if(ds[p.first][p.second]+1<ds[p.first+1][0])
          ds[p.first+1][0]=ds[p.first][p.second]+1,q.push_back({p.first+1,0});
      }
      else if(p.second+ad<g)
      {
        if(ds[p.first][p.second]<ds[p.first+1][p.second+ad])
          ds[p.first+1][p.second+ad]=ds[p.first][p.second],q.push_front({p.first+1,p.second+ad}); 
      }
    }
     if(p.first>1)
    {
      int ad=aa[p.first]-aa[p.first-1];
      if(p.second+ad==g)
      {
        if(ds[p.first][p.second]+1<ds[p.first-1][0])
          ds[p.first-1][0]=ds[p.first][p.second]+1,q.push_back({p.first-1,0});
      }
      else if(p.second+ad<g)
      {
        if(ds[p.first][p.second]<ds[p.first-1][p.second+ad])
          ds[p.first-1][p.second+ad]=ds[p.first][p.second],q.push_front({p.first-1,p.second+ad}); 
      }
    }
  }
  long ans=inf;
  if(ds[id][0]<inf)ans=(ds[id][0]-1)*(g+r)+g;
  for(int i=1;i<g;i++)
    if(ds[id][i]<inf)ans=min(ans,ds[id][i]*(g+r)+i);
  if(ans==inf)ans=-1;
  cout<<ans<<endl;
   return 0;
}