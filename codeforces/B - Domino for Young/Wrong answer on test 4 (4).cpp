/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2021 23:37                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 103900 KB                            
*  problem: https://codeforces.com/contest/1268/problem/B
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
const int N=3e5,inf=1e9,mod=998244353;
 int m=6,a[N+2],dp[N+2][(1<<6)+2];
int dfs(int id,int msk)
{
  if(dp[id][msk]!=-1)return dp[id][msk];
   vector<pair<int,int> >sg;int lt=0;
  int ret=inf;
  for(int i=1;i<=m;i++)
  {
    if(msk&(1<<(i-1)))
    {
      sg.push_back({lt+1,i-1});
      lt=i;
    }
  }
  sg.push_back({lt+1,a[id]});
  for(int i=(int)sg.size()-1;i>=0;i--)
  {
    if((sg[i].second-sg[i].first+1)%2==0)sg.erase(sg.begin()+i);
  }
  if(id==1)return dp[id][msk]=sg.size();
   int er=0;
  if((int)sg.size()==0)
  {
    ret=min(ret,dfs(id-1,0));
    return dp[id][msk]=ret;
  }
   if(sg.back().first>m)
  {
    sg.pop_back();er=1;
  }
  int sz=sg.size();
  for(int i=0;i<(1<<sz);i++)
  {
    int tmp=0;
    for(int j=0;j<sz;j++)if(i&(1<<j))tmp|=(1<<(sg[j].first-1));
    ret=min(ret,er+sz-__builtin_popcount(i)+dfs(id-1,tmp));
  }
  return dp[id][msk]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   memset(dp,-1,sizeof dp);
   int n;cin>>n;long tt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];tt+=a[i];
  }
  tt-=dfs(n,0);
  cout<<tt/2<<endl;
   return 0;
}