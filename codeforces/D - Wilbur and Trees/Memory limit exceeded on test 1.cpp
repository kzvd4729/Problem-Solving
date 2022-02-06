/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/18/2018 20:10                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/596/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int n,h,aa[N+2],vis[3][N+2][N+2][3];
double p,dp[3][N+2][N+2][3];
double dfs(int s1,int lo,int hi,int s2)
{
  if(vis[s1+1][lo][hi][s2+1])return dp[s1+1][lo][hi][s2+1];
  vis[s1+1][lo][hi][s2+1]=1;
   if(lo>hi)return 0;
   double here=0;
   ///left left
  int em;
  if(s1==-1)em=min(aa[lo]-aa[lo-1],h);
  else em=min(aa[lo]-aa[lo-1]-h,h);
  here+=0.5*p*em+0.5*p*dfs(-1,lo+1,hi,s2);
   ///left right
  em=aa[lo]+h;int i;
  for(i=lo+1;i<=hi;i++)
  {
    if(aa[i]>=em)break;
    em=aa[i]+h;
  }
  if(i>hi)
  {
    if(s2==1)em=min(em,aa[hi+1]);
    else em=min(em,aa[hi+1]-h);
  }
  em-=aa[lo];
  here+=0.5*(1.0-p)*em+0.5*(1.0-p)*dfs(1,i,hi,s2);
   ///right right
  if(s2==1)em=min(aa[hi+1]-aa[hi],h);
  else em=min(aa[hi+1]-aa[hi]-h,h);
  here+=0.5*(1.0-p)*em+0.5*(1.0-p)*dfs(s1,lo,hi-1,1);
   ///right left
  em=aa[hi]-h;
  for(i=hi-1;i>=lo;i--)
  {
    if(aa[i]<=em)break;
    em=aa[i]-h;
  }
  if(i<lo)
  {
    if(s1==-1)em=max(em,aa[lo-1]);
    else em=max(em,aa[lo-1]+h);
  }
  em=aa[hi]-em;
  here+=0.5*p*em+0.5*p*dfs(s1,lo,i,-1);
   return dp[s1+1][lo][hi][s2+1]=here;
 }
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>h>>p;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);aa[0]=-1e9,aa[n+1]=1e9;
  cout<<setprecision(9)<<fixed<<dfs(-1,1,n,1)<<endl;
  return 0;
}