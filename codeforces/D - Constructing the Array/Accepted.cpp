/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2020 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 15500 KB                             
*  problem: https://codeforces.com/contest/1353/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;priority_queue<vector<int> >pq;
    pq.push({n,-1,n});
     for(int i=1;i<=n;i++)
    {
      vector<int>v=pq.top();pq.pop();v[1]*=-1;
      if((v[2]-v[1]+1)%2)
      {
        int md=(v[1]+v[2])/2;//cout<<md<<endl;
        aa[md]=i;
        if(md!=v[1])pq.push({md-v[1],-v[1],md-1});
        if(md!=v[2])pq.push({v[2]-md,-(md+1),v[2]});
      }
      else
      {
        int md=(v[1]+v[2]-1)/2;//cout<<md<<endl;
        aa[md]=i;
        if(md!=v[1])pq.push({md-v[1],-v[1],md-1});
        if(md!=v[2])pq.push({v[2]-md,-(md+1),v[2]});
      }
    }
    for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<"\n";
  }
  return 0;
}