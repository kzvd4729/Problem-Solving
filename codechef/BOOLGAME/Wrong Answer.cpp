/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2021 15:41:06                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/APRIL21A/problems/BOOLGAME
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
const int N=60,inf=1e9,mod=1e9+7;
long g[N+2],ed[N+2][N+2],cs[N+2][N+2];
priority_queue<long,vector<long>,greater<long> >pq[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>g[i];
    memset(ed,0,sizeof ed);
    for(int i=1;i<=m;i++)
    {
      int u,v,d;cin>>u>>v>>d;
      ed[u][v]=d;
    }
    memset(cs,0,sizeof cs);
    for(int i=1;i<=n;i++)
    {
      for(int ls=0;ls<i;ls++)
      {
        for(int j=ls+1;j<=i;j++)
          cs[i][ls]+=ed[j][i];
      }
    }
    for(int i=1;i<=n+1;i++)
    {
      for(int j=0;j<=n;j++)
        while((int)pq[i][j].size())pq[i][j].pop();
    }
    pq[1][0].push(0);
    for(int i=1;i<=n+1;i++)
    {
      for(int ls=0;ls<i;ls++)
      {
        vector<long>v;
        while((int)pq[i][ls].size())v.push_back(pq[i][ls].top()),pq[i][ls].pop
            ();
        for(auto &x:v)pq[i][ls].push(x+cs[i-1][ls]),x+=cs[i-1][ls];
        if(i>n)continue;
        for(auto x:v)
        {
          pq[i+1][ls].push(x),pq[i+1][i].push(x+g[i]);
          if((int)pq[i+1][ls].size()>k)pq[i+1][ls].pop();
          if((int)pq[i+1][i].size()>k)pq[i+1][i].pop();
        }
      }
    }
    priority_queue<long,vector<long>,greater<long> >ans;
    for(int ls=0;ls<=n;ls++)
    {
      while((int)pq[n+1][ls].size())ans.push(pq[n+1][ls].top()),pq[n+1][ls].pop
          ();
      while((int)ans.size()>k)ans.pop();
    }
    vector<long>v;
    while((int)ans.size())v.push_back(ans.top()),ans.pop();
    for(int i=(int)v.size()-1;i>=0;i--)cout<<v[i]<<" ";cout<<endl;
  }
  return 0;
}