/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/03/2020 22:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 46400 KB                             
*  problem: https://codeforces.com/gym/102465/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int vis[N+2];
long fr[N+2],bk[N+2];
set<int>st[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=k;i++)
  {
    int x,y;cin>>x>>y;st[y].insert(x);
  }
  int cnt=0;
  for(int i=0;i<m;i++)
  {
    if(i)fr[i]=fr[i-1];fr[i]+=cnt;
    for(auto x:st[i])
    {
      cnt-=vis[x];vis[x]=1;
      cnt+=vis[x];
    }
  }
  memset(vis,0,sizeof(vis));
  cnt=0;
  for(int i=m-1;i>=0;i--)
  {
    bk[i]=bk[i+1];bk[i]+=cnt;
    for(auto x:st[i])
    {
      cnt-=vis[x];vis[x]=1;
      cnt+=vis[x];
    }
  }
  long mn=1LL*inf*inf;
  for(int i=0;i<m;i++)
  {
    if(fr[i]+bk[i]<mn)mn=fr[i]+bk[i];
  }
  cout<<mn+mn+n-1<<endl;
  return 0;
}