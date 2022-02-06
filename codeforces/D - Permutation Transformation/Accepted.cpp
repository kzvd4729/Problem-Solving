/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/16/2021 20:53                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1490/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2],n,ans[N+2];
void dfs(int lo,int hi,int d)
{
  if(lo>hi)return ;
  int mx=0,id=-1;
  for(int i=lo;i<=hi;i++)
  {
    if(a[i]>mx)mx=a[i],id=i;
  }
  ans[id]=d;
  dfs(lo,id-1,d+1);dfs(id+1,hi,d+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,n,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
      cout<<endl;
  }
  return 0;
}