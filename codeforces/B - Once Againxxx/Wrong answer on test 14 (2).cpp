/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2019 19:22                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 31600 KB                             
*  problem: https://codeforces.com/contest/582/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int aa[1000004],dp[N+N+2],pd[302][N+N+2],mx[302],fr[302];
int bit[1000003];
void upd(int x,int vl)
{
 for( ;x<=1000000;x+=x&-x)
  bit[x]=max(bit[x],vl);
}
int get(int x)
{
 int ret=0;
 for( ;x>0;x-=x&-x)
  ret=max(ret,bit[x]);
 return ret;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,t;cin>>n>>t;
 for(int i=1;i<=n;i++)
 {
  cin>>aa[i],fr[aa[i]]++;
 }
 for(int i=n+1;i<=3*n;i++)
  aa[i]=aa[i-n];
 for(int i=1;i<=3*n;i++)
 {
  dp[i]=1;
  for(int j=1;j<i;j++)
  {
   if(aa[j]<=aa[i])
    dp[i]=max(dp[i],dp[j]+1);
  }
 }
 for(int k=1;k<=300;k++)
 {
  for(int i=1;i<=3*n;i++)
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
 int ans=0;
 for(int i=1;i<=3*n;i++)
 {
  for(int j=aa[i];j<=300;j++) 
   ans=max(ans,dp[i]+fr[j]*(t-3*2)+mx[j]);
 }
 if(n*t<=1000000)
 {
  int ams=0;
  for(int i=n+1;i<=n*t;i++)
   aa[i]=aa[i-n];
  for(int i=1;i<=n*t;i++)
  {
   int x=get(aa[i]);
   ams=max(ams,x+1);upd(aa[i],x+1);
  }
  cout<<ams<<endl,exit(0);
 }
 cout<<ans<<endl;
 return 0;
}