/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2021 21:55                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++17 (64)                          
*  run_time: 1996 ms                                         memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1495/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=600,inf=1e9,mod=998244353;
 vector<int>ad[N+2],id[N+2],pr[2][N+2];
int d[N+2],ed[N+2][N+2];
void bfs(int sr,int n)
{
  for(int i=1;i<=n;i++)d[i]=inf;
  queue<int>q;q.push(sr);d[sr]=0;
   while((int)q.size())
  {
    int u=q.front();q.pop();
    int c=-1;
    for(auto x:ad[u])
    {
      c++;
      if(d[u]+1<d[x])
      {
        d[x]=d[u]+1;q.push(x);
        ed[sr][id[u][c]]=1;
      }
      else if(d[u]+1==d[x])ed[sr][id[u][c]]=1;
    }
  }
}
bool bfs2(int sr,int n,int f)
{
  for(int i=1;i<=n;i++)d[i]=inf;
  queue<int>q;q.push(sr);d[sr]=0;
   while((int)q.size())
  {
    int u=q.front();q.pop();
    int c=-1;
    for(auto x:ad[u])
    {
      c++;
      if(d[u]+1<d[x])
      {
        d[x]=d[u]+1;q.push(x);
        pr[f][x].push_back(id[u][c]);
      }
      else if(d[u]+1==d[x])
      {
        pr[f][x].push_back(id[u][c]);
        //cout<<c<<" "<<ad[u].size()<<" "<<id[u][c]<<endl;
      }
    }
  }
  for(int i=1;i<=n;i++)if(d[i]==inf)return false;
  return true;
}
int uu[N+2],vv[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
    id[u].push_back(i);id[v].push_back(i);
     uu[i]=u,vv[i]=v;
  }
  for(int i=1;i<=n;i++)bfs(i,n);
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=n;k++)ad[k].clear(),id[k].clear();
      for(int k=1;k<=m;k++)
      {
        if(ed[i][k] && ed[j][k])
        {
          ad[uu[k]].push_back(vv[k]),ad[vv[k]].push_back(uu[k]);
           id[uu[k]].push_back(k),id[vv[k]].push_back(k);
          //cout<<uu[k]<<" "<<vv[k]<<endl;
        }
      }
       for(int k=1;k<=n;k++)pr[0][k].clear(),pr[1][k].clear();
       int ans=1;
      if(bfs2(i,n,0)==0 || bfs2(j,n,1)==0)ans=0;
      for(int k=1;k<=m;k++)cnt[k]=0;
       for(int k=1;k<=n;k++)if((int)pr[1][k].size()>=2)for(auto x:pr[1][k])cnt[x]=1;
      //cout<<ans<<endl;
       //for(int k=1;k<=n;k++)for(auto x:pr[0][k])cout<<0<<" "<<k<<" "<<x<<endl;
      //for(int k=1;k<=n;k++)for(auto x:pr[1][k])cout<<1<<" "<<k<<" "<<x<<endl;
       for(int k=1;k<=n;k++)
      {
        int sz=pr[0][k].size(),now=0;
        if(sz<=1)continue;
        for(auto x:pr[0][k])now+=cnt[x];
          if(now==sz)ans=(1LL*ans*sz)%mod;
        if(now<sz-1)ans=0;
      }
      cout<<ans<<" ";
      //exit(0);
    }
    cout<<endl;
  }
   return 0;
}