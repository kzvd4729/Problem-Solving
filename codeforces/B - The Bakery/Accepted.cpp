/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2020 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 18600 KB                             
*  problem: https://codeforces.com/contest/833/problem/B
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
int a[N+2],fr[N+2],cnt,L=1,R=0,dp[50+2][35000+2];
int cal(int l,int r)
{
  for(int i=R+1;i<=r;i++)
  {
    fr[a[i]]++;if(fr[a[i]]==1)cnt++;
  }
  for(int i=l;i<L;i++)
  {
    fr[a[i]]++;if(fr[a[i]]==1)cnt++;
  }
  for(int i=r+1;i<=R;i++)
  {
    fr[a[i]]--;if(fr[a[i]]==0)cnt--; 
  }
  for(int i=L;i<l;i++)
  {
    fr[a[i]]--;if(fr[a[i]]==0)cnt--; 
  }
  L=l,R=r;return cnt;
}
void dfs(int i,int lo,int hi,int lt,int rt)
{
  if(lo>hi)return ;
  int j=(lo+hi)>>1,op;int &mn=dp[i][j],now;
  for(int k=lt,r=min(j,rt);k<=r;k++)
  {
    now=cal(k,j)+dp[i-1][k-1];
    if(now>mn)mn=now,op=k;
  }
  dfs(i,lo,j-1,lt,op);dfs(i,j+1,hi,op,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
   memset(dp,-60,sizeof dp);
  for(int i=0;i<50+2;i++)dp[i][0]=0;
   for(int i=1;i<=k;i++)dfs(i,1,n,1,n);
  cout<<dp[k][n]<<endl;
   return 0;
}