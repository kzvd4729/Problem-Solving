/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/03/2019 21:24                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/319/problem/C
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
  return ((fup*1.0)*sdw)<=((fdw*1.0)*sup);//for min <=
}
void addLine(pair<long,long>p)
{
  stk[++top]=p;
  while(top>=3&&isBad(top-2,top-1,top))
  {
    stk[top-1]=stk[top];top--;
  }
}
long getMin(long x)
{
  long lo=1,hi=top,md,on,tw;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    on=stk[md].first*x+stk[md].second;
    tw=stk[md+1].first*x+stk[md+1].second;
    if(tw<on)lo=md;else hi=md;//reverse for min
  }
  long ret=1e18;//check for min;
  for(md=lo;md<=hi;md++)
    ret=min(ret,stk[md].first*x+stk[md].second);//check for min
  return ret;
}
////////////////////////////////////////////
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>bb[i];
   addLine({bb[1],0});long now=0;
  for(int i=2;i<=n;i++)
  {
    now=getMin(aa[i]);addLine({bb[i],now});
  }
  cout<<now<<endl;
  return 0;
}