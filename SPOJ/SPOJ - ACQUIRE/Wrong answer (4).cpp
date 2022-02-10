/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-10-24 01:50:18                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-ACQUIRE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=500000;
const long inf=1e17;
long dp[N+2],top;
pair<long,long>pp[N+2],tmp[N+2],stk[N+2];
bool ck(long i,long j,long k)
{
  long fup=(stk[i].second-stk[k].second);
  long fdw=(stk[k].first-stk[i].first);

  long sup=(stk[i].second-stk[j].second);
  long sdw=(stk[j].first-stk[i].first);

  return fup*sdw<=fdw*sup;

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
  while(hi-lo>10)
  {
    md=(lo+hi)/2;
    long on=stk[md].first*x+stk[md].second;
    if(md==top)break;
    long tw=stk[md+1].first*x+stk[md+1].second;
    if(tw>on)lo=md;
    else hi=md;
  }
  long ret=inf;
  for(md=lo;md<=hi;md++)
    ret=min(ret,stk[md].first*x+stk[md].second);
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>pp[i].first>>pp[i].second;
  sort(pp+1,pp+n+1,greater<pair<long,long> >());
//  for(long i=1;i<=n;i++)
//    cout<<pp[i].first<<" "<<pp[i].second<<endl;
  long id=1;tmp[id]=pp[1];
  for(long i=2;i<=n;i++)
  {
    if(pp[i].second<=pp[id].second)continue;
    tmp[++id]=pp[i];
  }
  n=id;for(long i=1;i<=n;i++)pp[i]=tmp[i];
  add({pp[1].first,0});
  for(long i=1;i<=n;i++)
  {
    dp[i]=qry(pp[i].second);
    add({pp[i+1].first,dp[i]});
    //cout<<dp[i]<<" "<<top<<endl;
  }
  cout<<dp[n]<<endl;
  return 0;
}