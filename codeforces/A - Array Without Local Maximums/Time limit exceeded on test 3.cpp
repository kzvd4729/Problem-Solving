/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2021 14:46                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++17 (64)                          
*  run_time: 2000 ms                                         memory_used: 14900 KB                             
*  problem: https://codeforces.com/contest/1067/problem/A
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
 int n,a[N+2];
int dfs(int id,int ls,int f,int sm)
{
  if(ls<1 || ls>200)return 0;
  if(id==n)
  {
    if(sm==2)
    {
      if(a[id]!=-1)return a[id]<=ls;
      else return ls;
    }
    else if(sm==1)
    {
      if(a[id]!=-1)return ls==a[id];
      else return 1;
    }
    return 0;
  }
   int ret=0;
   if(f==0)
  {
    if(sm==0)assert(0);
     if(sm==2)
    {
      if(a[id]!=-1)
      {
        if(a[id]==ls)ret=(ret+dfs(id+1,a[id],f,2))%mod;
        else ret=(ret+dfs(id+1,a[id],f,1))%mod;
      }
      else
      {
        ret=(ret+dfs(id+1,ls,f,2))%mod;
        ret=(ret+dfs(id,ls+1,1,0))%mod;
        ret=(ret+dfs(id,ls-1,-1,0))%mod;
      }
    }
    else
    {
      if(a[id]!=-1)
      {
        if(a[id]==ls)ret=(ret+dfs(id+1,a[id],f,2))%mod;
        else if(a[id]>ls)ret=(ret+dfs(id+1,a[id],f,1))%mod;
      }
      else
      {
        ret=(ret+dfs(id+1,ls,f,2))%mod;
        ret=(ret+dfs(id,ls+1,1,0))%mod;
      }
    }
  }
  else if(f==1)
  {
    if(a[id]!=-1)assert(0);
     //cout<<id<<" "<<ls<<endl;
     ret=(ret+dfs(id+1,ls,0,1));
    ret=(ret+dfs(id,ls+1,f,0));
  }
  else if(f==-1)
  {
    if(a[id]!=-1)assert(0);
     ret=(ret+dfs(id+1,ls,0,1));
    ret=(ret+dfs(id,ls-1,f,0));
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
    if(a[1]==-1)cout<<dfs(1,1,1,0)<<endl;
  else cout<<dfs(2,a[1],0,1)<<endl;
      return 0;
}