/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-02 14:59:52                      
*  solution_verdict: TLE                                     language: C++14 (GCC 5.4.1)                       
*  run_time: 2112 ms                                         memory_used: 142852 KB                            
*  problem: https://atcoder.jp/contests/agc032/tasks/agc032_b
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2],bb[N+2],rq[N+2],n;
vector<pair<int,int> >ed;
void dfs(int i,vector<pair<int,int> >v)
{
  if(i==ed.size())
  {
    for(int j=1;j<=n;j++)if(rq[j])return ;
    cout<<v.size()<<endl;
    for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
    exit(0);
  }
  if(rq[ed[i].first]>=ed[i].second&&rq[ed[i].second]>=ed[i].first)
  {
    rq[ed[i].first]-=ed[i].second;rq[ed[i].second]-=ed[i].first;
    v.push_back(ed[i]);dfs(i+1,v);v.pop_back();
    rq[ed[i].first]+=ed[i].second;rq[ed[i].second]+=ed[i].first;
  }
  dfs(i+1,v);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;int tr=(n*(n-1))/2;if(n%2==0)tr--;
   for(int i=1;i<=n;i++)rq[i]=tr;
  for(int i=n;i>=1;i--)
  {
    for(int j=i-1;j>=1;j--)
      ed.push_back({i,j});
  }
  vector<pair<int,int> >v;
  dfs(0,v);
  return 0;
}