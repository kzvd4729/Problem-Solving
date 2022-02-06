/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2021 20:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 576 ms                                          memory_used: 10800 KB                             
*  problem: https://codeforces.com/gym/102966/problem/N
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
const int N=100,inf=1e9,mod=1e9+7;
 int n,k,f,nm[N+2],pm[N+2],flag;
vector<pair<int,int> >ad[N+2];
 bool vs[N+2][N+2][(1<<10)+2];
void dfs(int nd,int cp,int msk)
{
  if(nm[nd])msk|=(1<<(nm[nd]-1));
  if(vs[nd][cp][msk])return ;
  vs[nd][cp][msk]=1;
    if((nd==1)&&(msk==((1<<k)-1)))
  {
    flag=1;return ;
  }
  cp=min(f,cp+pm[nd]);
  for(auto x:ad[nd])
  {
    if(flag)return ;
    if(x.second<=cp)
      dfs(x.first,cp-x.second,msk);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m>>k>>f;
   for(int i=1;i<=k;i++)
  {
    int x;cin>>x;
    nm[x]=i;
  }
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;
    ad[u].push_back({v,w});
    ad[v].push_back({u,w});
  }
  int p;cin>>p;
  for(int i=1;i<=p;i++)
  {
    int id,f;cin>>id>>f;
    pm[id]=f;
  }
   int lo=0,hi=f,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    memset(vs,0,sizeof vs);flag=0;
    dfs(1,md,0);
     if(flag)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    memset(vs,0,sizeof vs);flag=0;
    dfs(1,md,0);
     if(flag)break;
  }
  if(md>f)md=-1;
  cout<<md<<endl;
    return 0;
}