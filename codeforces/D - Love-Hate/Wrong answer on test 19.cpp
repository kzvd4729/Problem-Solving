/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/01/2021 22:06                        
*  solution_verdict: Wrong answer on test 19                 language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/1523/problem/D
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
const int N=2e5,inf=1e9,mod=1000000007;
 string a[N+2];
int n,m,dp[N+2];
 pair<int,string>solve(int id)
{
  vector<int>ind;int cnt=0;
  for(int i=0;i<(int)a[id].size();i++)
  {
    if(a[id][i]=='1')ind.push_back(i),cnt++;
  }
  for(int i=0;i<(1<<cnt);i++)dp[i]=0;
   for(int i=0;i<n;i++)
  {
    int msk=0;
    for(int j=0;j<(int)ind.size();j++)
    {
      if(a[i][ind[j]]=='1')msk|=(1<<j);
    }
    dp[msk]++;
  }
   for(int i=0;i<cnt;i++)
  {
    for(int msk=(1<<cnt)-1;msk>=0;msk--)
    {
      if(!(msk&(1<<i)))
        dp[msk]+=dp[msk^(1<<i)];
    }
  }
  int mx=-1,msk=0;
  for(int i=0;i<(1<<cnt);i++)
  {
    if(dp[i]>=(n+1)/2)
    {
      int x=__builtin_popcount(i);
      if(x>mx)mx=x,msk=i;
    }
  }
  string s;s.assign(m,'0');
  for(int i=0;i<cnt;i++)
  {
    if(msk&(1<<i))s[ind[i]]='1';
  }
   return {mx,s};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int p;cin>>n>>m>>p;
  for(int i=0;i<n;i++)cin>>a[i];
   vector<int>v;
  for(int i=0;i<n;i++)v.push_back(i);
  shuffle(v.begin(),v.end(),rng);
   int th=min(5,(int)v.size());
   int mx=0;string ans;ans.assign(m,'0');
  for(int l=0;l<th;l++)
  {
    int id=v[l];
    pair<int,string>p=solve(id);
    if(p.first>mx)mx=p.first,ans=p.second;
    //mx=max(mx,solve(id));
  }
  cout<<ans<<endl;
    return 0;
}