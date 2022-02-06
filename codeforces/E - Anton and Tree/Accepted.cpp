/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/04/2020 12:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 25400 KB                             
*  problem: https://codeforces.com/contest/734/problem/E
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
int cl[N+2],ds[N+2];
vector<int>adj[N+2];
void bfs(int sr,int n)
{
  for(int i=1;i<=n;i++)ds[i]=1e9;
  deque<int>q;q.push_back(sr);ds[sr]=0;
    while(q.size())
  {
    int u=q.front();q.pop_front();
    for(auto x:adj[u])
    {
      if(cl[u]==cl[x])
      {
        if(ds[u]<ds[x])
        {
          ds[x]=ds[u];q.push_front(x);
        }
      }
      else
      {
        if(ds[u]+1<ds[x])
        {
          ds[x]=ds[u]+1;q.push_back(x);
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>cl[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  bfs(1,n);int mx=-1,nd=0;
  for(int i=1;i<=n;i++)if(ds[i]>mx)mx=ds[i],nd=i;
  bfs(nd,n);mx=-1;//cout<<nd<<endl;
  for(int i=1;i<=n;i++)if(ds[i]>mx)mx=ds[i];cout<<(mx+1)/2<<endl;
  return 0;
}