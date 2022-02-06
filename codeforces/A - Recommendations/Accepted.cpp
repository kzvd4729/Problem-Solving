/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2020 14:04                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 155 ms                                          memory_used: 17200 KB                             
*  problem: https://codeforces.com/contest/1314/problem/A
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
int aa[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i].first;
  for(int i=1;i<=n;i++)cin>>pp[i].second;
  sort(pp+1,pp+n+1);
   for(int i=1;i<=n;i++)aa[i]=pp[i].first;
  priority_queue<int>pq;
   long ans=0,sm=0;
  for(int i=1;i<=2000000000;i++)
  {
    int id=lower_bound(aa+1,aa+n+1,i)-aa;
    if(sm==0)
    {
      if(id>n)break;else i=aa[id];
    }
    for(int j=id;j<=n;j++)
    {
      if(aa[j]==i)pq.push(pp[j].second),sm+=pp[j].second;
      else break;
    }
    assert(pq.size());
    int t=pq.top();pq.pop();sm-=t;
    ans+=sm;
  }
  cout<<ans<<endl;
  return 0;
}