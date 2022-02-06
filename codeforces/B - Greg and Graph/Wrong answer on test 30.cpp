/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/16/2019 19:12                        
*  solution_verdict: Wrong answer on test 30                 language: GNU C++14                               
*  run_time: 530 ms                                          memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/295/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500;
int mt[N+2][N+2],aa[N+2],ans[N+2],vis[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
   cin>>mt[i][j];
  }
 }
 for(int i=1;i<=n;i++)cin>>aa[i];
 for(int k=n;k>=1;k--)
 {
  vis[aa[k]]=1;
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=n;j++)
   {
    mt[i][j]=min(mt[i][j],mt[i][aa[k]]+mt[aa[k]][j]);
   }
  }
  for(int i=1;i<=n;i++)
  {
   if(!vis[i])continue;
   for(int j=1;j<=n;j++)
   {
    if(!vis[j])continue;
    ans[k]+=mt[i][j];
   }
  }
 }
 for(int i=1;i<=n;i++)
  cout<<ans[i]<<" ";
 cout<<endl;
 return 0;
}