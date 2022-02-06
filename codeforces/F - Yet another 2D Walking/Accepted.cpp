/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 18:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 217 ms                                          memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/1066/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5,inf=1e17;
long id,dp[N+2][3];
struct data
{
  long x,y;
}aa[N+2];
struct huge
{
  long mnx,y,x,mny;
}fn[N+2];
bool cmp(data A,data B)
{
  return max(A.x,A.y)<max(B.x,B.y);
}
long dfs(long st,long ls)
{
  if(st>id)return 0;
  if(dp[st][ls]!=-1)return dp[st][ls];
  long here=inf;
  if(!ls)
  {
    long ex=abs(fn[st-1].mnx-fn[st].mnx)+abs(fn[st-1].y-fn[st].y);
    ex+=abs(fn[st].mnx-fn[st].x)+abs(fn[st].y-fn[st].mny);
    here=min(here,ex+dfs(st+1,1));
    ex=abs(fn[st-1].mnx-fn[st].x)+abs(fn[st-1].y-fn[st].mny);
    ex+=abs(fn[st].mnx-fn[st].x)+abs(fn[st].y-fn[st].mny);
    here=min(here,ex+dfs(st+1,0));
  }
  else
  {
    long ex=abs(fn[st-1].x-fn[st].mnx)+abs(fn[st-1].mny-fn[st].y);
    ex+=abs(fn[st].mnx-fn[st].x)+abs(fn[st].y-fn[st].mny);
    here=min(here,ex+dfs(st+1,1));
    ex=abs(fn[st-1].x-fn[st].x)+abs(fn[st-1].mny-fn[st].mny);
    ex+=abs(fn[st].mnx-fn[st].x)+abs(fn[st].y-fn[st].mny);
    here=min(here,ex+dfs(st+1,0));
  }
  return dp[st][ls]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>aa[i].x>>aa[i].y;
  sort(aa+1,aa+n+1,cmp);
 //  cout<<endl<<endl;
//  for(int i=1;i<=n;i++)
//    cout<<aa[i].x<<" "<<aa[i].y<<endl;
   fn[0]={0,0,0,0};
  for(long i=1;i<=n;)
  {
    long mx=max(aa[i].x,aa[i].y);long j=i;
    fn[++id]={aa[i].x,aa[i].y,aa[i].x,aa[i].y};
    while(++j<=n)
    {
      if(mx==max(aa[j].x,aa[j].y))
      {
        if(aa[j].x<=fn[id].mnx)
          fn[id].mnx=aa[j].x,fn[id].y=max(fn[id].y,aa[j].y);
        if(aa[j].y<=fn[id].mny)
          fn[id].x=max(fn[id].x,aa[j].x),fn[id].mny=aa[j].y;
      }
      else break;
    }
    i=j;
  }
 //  for(int i=1;i<=id;i++)
//    cout<<fn[i].mnx<<" "<<fn[i].y<<" "<<fn[i].x<<" "<<fn[i].mny<<endl;
   memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}