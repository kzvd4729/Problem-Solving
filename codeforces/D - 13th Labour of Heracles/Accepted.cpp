/****************************************************************************************
*  @author: kzvd4729#                                        created: May/02/2021 13:46                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 171 ms                                          memory_used: 9900 KB                              
*  problem: https://codeforces.com/contest/1466/problem/D
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
 int dg[N+2],a[N+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;long ans=0;
    for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
     for(int i=1;i<=n;i++)dg[i]=0;
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      dg[u]++,dg[v]++;
    }
     priority_queue<pair<int,int> >pq;
    for(int i=1;i<=n;i++)if(dg[i]>1)pq.push({a[i],dg[i]});
     for(int i=1;i<n-1;i++)
    {
      cout<<ans<<" ";
       pair<int,int>p=pq.top();pq.pop();
      ans+=p.first;
       p.second--;
      if(p.second>1)pq.push({p.first,p.second});
    }
    cout<<ans<<'\n';
  }
  return 0;
}