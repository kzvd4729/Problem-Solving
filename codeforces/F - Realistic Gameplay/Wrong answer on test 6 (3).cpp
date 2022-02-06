/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/13/2020 13:49                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/1430/problem/F
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
const long inf=1e18;
int l[N+2],r[N+2],a[N+2],n,k;
map<int,long>dp[2000+2][2];
long dfs(int i,int rm,int f)
{
  if(i>n)return 0;
  if(dp[i][f].count(rm))return dp[i][f][rm];
  long ret=inf;
   if(a[i]<=rm)
  {
    if(l[i]==r[i]&&r[i]==l[i+1])ret=min(ret,dfs(i+1,rm-a[i],0));
    else ret=min(ret,dfs(i+1,rm-a[i],1));
  }
  if(f&&a[i]<=k)
  {
    if(l[i]==r[i]&&r[i]==l[i+1])ret=min(ret,rm+dfs(i+1,k-a[i],0));
    else ret=min(ret,rm+dfs(i+1,k-a[i],1));
  }
  int tr=a[i],day=0;
  day++,tr=max(0,tr-rm);
  day+=(tr+k-1)/k;
   if(day<=r[i]-l[i]+1)
  {
    if(day==r[i]-l[i]+1&&r[i]==l[i+1])ret=min(ret,dfs(i+1,(k-(tr%k))%k,0));
    else ret=min(ret,dfs(i+1,k-(tr%k),1));
  }
  tr=a[i];day=(tr+k-1)/k;
  if(f&&day<=r[i]-l[i]+1)
  {
    if(day==r[i]-l[i]+1&&r[i]==l[i+1])ret=min(ret,rm+dfs(i+1,(k-(tr%k))%k,0));
    else ret=min(ret,rm+dfs(i+1,k-(tr%k),1));
  }
  return dp[i][f][rm]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;long tt=0;
  for(int i=1;i<=n;i++)cin>>l[i]>>r[i]>>a[i],tt+=a[i];
   long ans=dfs(1,k,1);
  if(ans==inf)cout<<-1<<endl;
  else cout<<tt+ans<<endl;
   return 0;
}