/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2021 13:56                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 93 ms                                           memory_used: 34500 KB                             
*  problem: https://codeforces.com/contest/1067/problem/B
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
const int N=1e6,inf=1e9,mod=1e9+7;
 vector<int>ad[N+2];
int d[N+2],qd[N+2];
void spfa(int n)
{
  for(int i=1;i<=n;i++)d[i]=inf,qd[i]=0;
  queue<int>q;
   for(int i=1;i<=n;i++)
  {
    if((int)ad[i].size()==1)
    {
      q.push(i);qd[i]=1,d[i]=0;
    }
  }
  while(q.size())
  {
    int u=q.front();q.pop();qd[u]=0;
    for(auto x:ad[u])
    {
      if(d[u]+1<d[x])
      {
        d[x]=d[u]+1;
        if(!qd[x])q.push(x),qd[x]=1;
      }
    }
  }
}
 void no(){cout<<"No"<<endl,exit(0);}
 void dfs(int nd,int pr,int h)
{
  int ch=0;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    ch++;dfs(x,nd,h-1);
  }
   if(ch==0)
  {
    if(h!=0)no();
    return ;
  }
  if(ch<3)no();
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    ad[u].push_back(v);ad[v].push_back(u);
  }
   spfa(n);
   int mx=-1,nd;
  for(int i=1;i<=n;i++)if(d[i]>mx)mx=d[i],nd=i;
   if(mx!=k)no();
    dfs(nd,-1,k);
  cout<<"Yes"<<endl;
      return 0;
}