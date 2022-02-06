/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/23/2021 21:14                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1517/problem/C
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
const int N=500,inf=1e9,mod=1e9+7;
 int a[N+2][N+2],cnt,n;
 void dfs(int i,int j,int m)
{
  if(cnt==0)return ;
  if(j-1>=1 && a[i][j-1]==0)
  {
    a[i][j-1]=m;cnt--;
    dfs(i,j-1,m);
  }
   if(cnt==0)return ;
  if(i+1<=n && a[i+1][j]==0)
  {
    a[i+1][j]=m;cnt--;
    dfs(i+1,j,m);
  }
}
 bool solve(vector<int>v)
{
  memset(a,0,sizeof a);
  n=v.size();
  for(int i=1;i<=n;i++)
    a[i][i]=v[i-1];
   for(int i=1;i<=n;i++)
  {
    cnt=a[i][i]-1;
    dfs(i,i,a[i][i]);
     if(cnt!=0)return false;
  }
  return true;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;vector<int>v(n);
  for(int i=1;i<=n;i++)cin>>v[i-1];
   if(solve(v)==0)assert(0);
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(a[i][j]==0)continue;
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
    return 0;
} 