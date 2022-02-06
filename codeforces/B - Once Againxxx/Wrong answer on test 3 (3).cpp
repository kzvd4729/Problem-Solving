/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2019 18:43                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/582/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int aa[N+2],dp[N+2],pd[302][N+2],mx[302],fr[302],nx[302];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,t;cin>>n>>t;
 for(int i=1;i<=n;i++)cin>>aa[i],fr[aa[i]]++;
 for(int i=1;i<=n;i++)
 {
  dp[i]=1;
  for(int j=1;j<i;j++)
  {
   if(aa[j]<=aa[i])
    dp[i]=max(dp[i],dp[j]+1);
  }
 }
 if(t==1)
 {
  int mx=0;
  for(int i=1;i<=n;i++)
   mx=max(mx,dp[i]);
  cout<<mx<<endl,exit(0);
 }
 for(int k=1;k<=300;k++)
 {
  for(int i=1;i<=n;i++)
  {
   if(aa[i]<k)continue;
   pd[k][i]=1;
   for(int j=1;j<i;j++)
   {
    if(aa[j]<k)continue;
    if(aa[j]<=aa[i])
     pd[k][i]=max(pd[k][i],pd[k][j]+1);
   }
   mx[k]=max(mx[k],pd[k][i]);
  }
 }
 memset(pd,0,sizeof(pd));
 for(int k=1;k<=300;k++)
 {
  for(int i=1;i<=n;i++)
  {
   if(aa[i]>k)continue;
   pd[k][i]=1;
   for(int j=1;j<i;j++)
   {
    if(aa[j]>k)continue;
    if(aa[j]<=aa[i])
     pd[k][i]=max(pd[k][i],pd[k][j]+1);
   }
   nx[k]=max(nx[k],pd[k][i]);
  }
 }
 int ans=0;
 for(int i=1;i<=300;i++)
  ans=max(ans,nx[i]+fr[i]*(t-2)+mx[i]);
 cout<<ans<<endl;
 return 0;
}