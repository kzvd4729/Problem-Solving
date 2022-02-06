/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2018 14:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/319/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
const long inf=1e18;
long aa[N+2],bb[N+2],dp[N+2],top;
pair<long,long>stk[N+2];
bool ck(long i,long j,long k)
{
  long fup=(stk[i].second-stk[k].second);
  long fdw=(stk[k].first-stk[i].first);
   long sup=(stk[i].second-stk[j].second);
  long sdw=(stk[j].first-stk[i].first);
   //return ((fup*1.0)/(fdw*1.0))<=((sup*1.0)/(sdw*1.0));
   return ((fup*1.0)*sdw)<=((fdw*1.0)*sup);
 }
void add(pair<long,long>p)
{
  stk[++top]=p;
  while(top>=3&&ck(top-2,top-1,top))
  {
    stk[top-1]=stk[top];
    top--;
  }
}
long qry(long x)
{
  long lo=1,hi=top,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long on=stk[md].first*x+stk[md].second;
    if(md==top)break;
    long tw=stk[md+1].first*x+stk[md+1].second;
    if(tw<on)lo=md;
    else hi=md;
  }
  long ret=inf;
  for(md=lo;md<=hi;md++)
    ret=min(ret,stk[md].first*x+stk[md].second);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=1;i<=n;i++)
    cin>>bb[i];
  dp[1]=0;add({bb[1],dp[1]});
  for(long i=2;i<=n;i++)
  {
    dp[i]=qry(aa[i]);add({bb[i],dp[i]});
  }
  cout<<dp[n]<<endl;
  return 0;
}