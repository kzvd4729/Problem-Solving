/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2020 23:25                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 86100 KB                             
*  problem: https://codeforces.com/contest/1408/problem/G
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
const int N=2e6,mod=998244353;
int a[N+2],b[N+2],pr[N+2],vs[N+2],id[N+2],tmp[N+2],n;
int dp[2000+2][2000+2];
vector<int>ad[N+2];
int dfs(int i,int k)
{
  if(k<0)return 0;if(i==n)return k==0;
  if(dp[i][k]!=-1)return dp[i][k];
  int ret=0;
  for(auto x:ad[i])
    ret=(ret+dfs(i+x,k-1))%mod;
  return dp[i][k]=ret;
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;vector<int>v;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int x;cin>>x;if(j<i)continue;
      a[x]=i,b[x]=j;
    }
  }
  int m=(n*(n-1))/2;
  //for(int i=1;i<=m;i++)cout<<a[i]<<" * "<<b[i]<<endl;
  for(int i=1;i<=m;i++)
  {
    if(vs[a[i]]==0)v.push_back(a[i]);
    if(vs[b[i]]==0)v.push_back(b[i]);
    vs[a[i]]=1,vs[b[i]]=1;
  }
  //for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
  for(int i=0;i<v.size();i++)id[v[i]]=i,ad[i].push_back(1);
  for(int i=1;i<=m;i++)
  {
    int nd=0,ed=0;
    for(int j=i;j<=m;j++)
    {
      if(pr[a[j]]||pr[b[j]])break;
      ed++;if(tmp[a[j]]==0)nd++;if(tmp[b[j]]==0)nd++;
      tmp[a[j]]=1;tmp[b[j]]=1;
       //cout<<i<<" --> "<<ed<<" "<<nd<<endl;
       if(ed==(nd*(nd-1))/2)ad[id[a[i]]].push_back(nd);
    }
    for(int j=i;j<=m;j++)
    {
      if(pr[a[j]]||pr[b[j]])break;
      tmp[a[j]]=0;tmp[b[j]]=0;
    }
    pr[a[i]]=1;pr[b[i]]=1;
  }
  memset(dp,-1,sizeof dp);
  for(int k=1;k<=n;k++)
    cout<<dfs(0,k)<<" ";
  cout<<endl;
  return 0;
}