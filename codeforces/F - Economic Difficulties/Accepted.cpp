/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2019 13:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 498 ms                                          memory_used: 78600 KB                             
*  problem: https://codeforces.com/contest/1263/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int xx[N+2],yy[N+2],lva[N+2],lvb[N+2];
int para[N+2],parb[N+2];
vector<int>aa[N+2],bb[N+2];
void dfs1(int node,int l)
{
  lva[node]=l;
  for(auto x:aa[node])dfs1(x,l+1);
}
void dfs2(int node,int l)
{
  lvb[node]=l;
  for(auto x:bb[node])dfs2(x,l+1);
}
int lca(int f,int a,int b)
{
  int cnt=0;if(!a)cnt--;
  if(f==1)
  {
    while(lva[b]>lva[a])
    {
      cnt++;b=para[b];
    }
    while(lva[a]>lva[b])
    {
      a=para[a];
    }
    while(a!=b)
    {
      cnt++;a=para[a],b=para[b];
    }
  }
  else
  {
    while(lvb[b]>lvb[a])
    {
      cnt++;b=parb[b];
    }
    while(lvb[a]>lvb[b])
    {
      a=parb[a];
    }
    while(a!=b)
    {
      cnt++;a=parb[a],b=parb[b];
    }
  }
  return cnt;
}
int dp[2000+2][2000+2][2],n;
int dfs(int ls,int now,int f)
{
  if(now>n)return 0;
  if(dp[ls][now][f]!=-1)return dp[ls][now][f];
  int ret=1e9;
  if(f==1)
  {
    ret=min(ret,lca(1,xx[now-1],xx[now])+dfs(ls,now+1,1));
    ret=min(ret,lca(2,yy[ls-1],yy[now])+dfs(now,now+1,2));
  }
  else
  {
    ret=min(ret,lca(2,yy[now-1],yy[now])+dfs(ls,now+1,2));
    ret=min(ret,lca(1,xx[ls-1],xx[now])+dfs(now,now+1,1));
  }
  return dp[ls][now][f]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   int a;cin>>a;
  for(int i=2;i<=a;i++)
  {
    int x;cin>>x;aa[x].push_back(i);
    para[i]=x;
  }
  for(int i=1;i<=n;i++)cin>>xx[i];
   int b;cin>>b;
  for(int i=2;i<=b;i++)
  {
    int x;cin>>x;bb[x].push_back(i);
    parb[i]=x;
  }
  for(int i=1;i<=n;i++)cin>>yy[i];
   dfs1(1,0);dfs2(1,0);
   memset(dp,-1,sizeof(dp));
   cout<<a+b-dfs(0,1,1)-2<<endl;
      return 0;
}