/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2019 21:29:31                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 22.6M                                
*  problem: https://www.codechef.com/JULY19A/problems/CCC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long inf=1e18;
long aa[N+2],dp[N+2][N+2];
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
  long ret=inf;//check for min;
  for(md=lo;md<=hi;md++)
    ret=min(ret,stk[md].first*x+stk[md].second);
  return ret;
}
////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
        dp[i][j]=inf;
    for(int i=n;i>=1;i--)
      dp[i][1]=aa[i]*(n-i+1);
    for(int j=2;j<=k;j++)
    {
      top=0;
      for(int i=n;i>=1;i--)
      {
        dp[i][j]=getMin(aa[i])-(aa[i]*i);
        addLine({i,dp[i][j-1]});
      }
    }
    /*for(int i=1;i<=n;i++)
      cout<<dp[i][2]<<" ";
    cout<<endl;*/
    long ans=inf;
    for(int i=1;i<=n;i++)
      ans=min(ans,dp[i][k]);
    cout<<ans<<"\n";
  }
  return 0;
}
/*
1
7 4
1 1 1 6 6 9 9
30
*/