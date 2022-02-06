/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2019 19:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1559 ms                                         memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/1083/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************ Convex Hull Trick ***********/
pair<long,long>stk[N+2];int top;
bool isBad(int i,int j,int k)
{
  long fup,fdw,sup,sdw;
  fup=(stk[i].second-stk[k].second);fdw=(stk[k].first-stk[i].first);
  sup=(stk[i].second-stk[j].second);sdw=(stk[j].first-stk[i].first);
  return ((fup*1.0)*sdw)>=((fdw*1.0)*sup);
}
void addLine(pair<long,long>p)
{
  stk[++top]=p;
  while(top>=3&&isBad(top-2,top-1,top))
  {
    stk[top-1]=stk[top];top--;
  }
}
long getMax(long x)
{
  long lo=1,hi=top,md,on,tw;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    on=stk[md].first*x+stk[md].second;
    tw=stk[md+1].first*x+stk[md+1].second;
    if(tw<on)hi=md;else lo=md;
  }
  long ret=0;
  for(md=lo;md<=hi;md++)
    ret=max(ret,stk[md].first*x+stk[md].second);
  return ret;
}
////////////////////////////////////////////
struct data
{
  long a,b,c;
}aa[N+2];
bool cmp(data A,data B)
{
  return A.a<B.a;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i].a>>aa[i].b>>aa[i].c;
  sort(aa+1,aa+n+1,cmp);addLine({0,0});long ans=0;
  for(int i=1;i<=n;i++)
  {
    long now=getMax(aa[i].b)+aa[i].a*aa[i].b-aa[i].c;
    addLine({-aa[i].a,now});ans=max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}