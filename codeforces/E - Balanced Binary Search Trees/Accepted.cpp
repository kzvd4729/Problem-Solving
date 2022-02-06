/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/09/2020 20:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1237/problem/E
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
const int N=1e6;
bool dfs(int lo,int hi,int p)
{
  if(hi<lo)return 1;
  if((hi-lo+1)%2)
  {
    int md=(lo+hi)/2;
    if(md%2!=p)return 0;
    return (dfs(lo,md-1,!(md%2))&dfs(md+1,hi,md%2));
  }
  else
  {
    int md=(lo+hi)/2;
    bool ret=0;
     if(md%2==p)ret|=(dfs(lo,md-1,!(md%2))&dfs(md+1,hi,md%2));
    md++;
    if(md%2==p)ret|=(dfs(lo,md-1,!(md%2))&dfs(md+1,hi,md%2));
     return ret;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,ans=0;cin>>n;
  int lo=1,hi=n;
  if(n%2)
  {
    int md=(lo+hi)/2;
    ans=(dfs(lo,md-1,!(md%2))&dfs(md+1,hi,md%2));
  }
  else
  {
    int md=(lo+hi)/2;
    ans|=(dfs(lo,md-1,!(md%2))&dfs(md+1,hi,md%2));
    md++;
    ans|=(dfs(lo,md-1,!(md%2))&dfs(md+1,hi,md%2));
  }
  cout<<ans<<endl;
    return 0;
}