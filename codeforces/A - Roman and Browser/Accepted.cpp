/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2019 20:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1100/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=100;
int n,k,aa[N+2],vis[N+2];
int ck(int x)
{
  memset(vis,0,sizeof(vis));
  for(int i=x;i<=n;i+=k)
    vis[i]=1;
  for(int i=x;i>=1;i-=k)
    vis[i]=1;
  int a=0,b=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    if(aa[i]==-1)b++;
    else a++;
  }
  return abs(a-b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,ck(i));
  cout<<ans<<endl;
  return 0;
}