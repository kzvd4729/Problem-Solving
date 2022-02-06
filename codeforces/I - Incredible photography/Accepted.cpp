/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2021 23:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 14100 KB                             
*  problem: https://codeforces.com/gym/102700/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e5;
const int inf=1e9;
int a[N+2],l[N+2],r[N+2],l2[N+2],r2[N+2];
long dp[N+2];
long dfs(int id)
{
  if(dp[id]!=-1)return dp[id];
  long ret=0;
  if(l[id]!=-1)ret=max(ret,id-l[id]+dfs(l[id]));
  if(r[id]!=-1)ret=max(ret,r[id]-id+dfs(r[id]));
  if(l2[id]!=-1)ret=max(ret,id-l2[id]+dfs(l2[id]));
  if(r2[id]!=-1)ret=max(ret,r2[id]-id+dfs(r2[id]));
   return dp[id]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   stack<pair<int,int> >st;
  memset(l,-1,sizeof l);
  for(int i=1;i<=n;i++)
  {
    while((int)st.size())
    {
      if(st.top().first<=a[i])st.pop();
      else break;
    }
    if((int)st.size())l[i]=st.top().second;
    st.push({a[i],i});
  }
  while((int)st.size())st.pop();
  memset(r,-1,sizeof r);
  for(int i=n;i>=1;i--)
  {
    while((int)st.size())
    {
      if(st.top().first<=a[i])st.pop();
      else break;
    }
    if((int)st.size())r[i]=st.top().second;
    st.push({a[i],i});
  }
    while((int)st.size())st.pop();
  memset(l2,-1,sizeof l2);
  for(int i=1;i<=n;i++)
  {
    int id=i;
    while((int)st.size())
    {
      if(st.top().first==a[i])id=st.top().second;
      if(st.top().first<=a[i])st.pop();
      else break;
    }
    if((int)st.size())l2[i]=st.top().second;
    st.push({a[i],id});
  }
  while((int)st.size())st.pop();
  memset(r2,-1,sizeof r2);
  for(int i=n;i>=1;i--)
  {
    int id=i;
    while((int)st.size())
    {
      if(st.top().first==a[i])id=st.top().second;
      if(st.top().first<=a[i])st.pop();
      else break;
    }
    if((int)st.size())r2[i]=st.top().second;
    st.push({a[i],id});
  }
  memset(dp,-1,sizeof dp);
  for(int i=1;i<=n;i++)cout<<dfs(i)<<" ";
    cout<<endl;
   return 0;
}