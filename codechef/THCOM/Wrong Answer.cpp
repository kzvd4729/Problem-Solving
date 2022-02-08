/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2019 01:03:11                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.48 sec                                        memory_used: 84.1M                                
*  problem: https://www.codechef.com/ALKH2019/problems/THCOM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e3;
const long inf=1e18;
long ds[N+2][N+2];
vector<pair<long,long> >adj[N+2],qr[N+2],ans;
/************ Convex Hull Trick ***********/
pair<long,long>stk[N+2];long top;
bool isBad(long i,long j,long k)
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
long getMax(long x)
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
void dfs(long node,long cs,long cnt)
{
  if(cs>ds[node][cnt])return ;
  ds[node][cnt]=cs;
  for(auto x:adj[node])
    dfs(x.second,cs+x.first,cnt+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=m;i++)
  {
    long u,v,w;cin>>u>>v>>w;
    adj[u].push_back({w,v});
  }
  for(long i=1;i<=n;i++)
  {
    sort(adj[i].begin(),adj[i].end());
    for(long j=0;j<=n;j++)
      ds[i][j]=inf;
  }
  dfs(1,0,0);
  long q;cin>>q;long ad=0;
  for(long i=1;i<=q;i++)
  {
    long ty,k;cin>>ty>>k;
    if(ty==1)ad+=k;
    else qr[k].push_back({ad,i});
  }
  for(long i=1;i<=n;i++)
  {
    long f=0;
    for(long j=0;j<=n;j++)
    {
      if(ds[i][j]<inf)
        f=1,addLine({j,ds[i][j]});
    }
    for(auto x:qr[i])
    {
      if(!f)ans.push_back({x.second,inf});
      else ans.push_back({x.second,getMax(x.first)});
    }
    top=0;
  }
  for(auto x:ans)
  {
    if(x.second==inf)cout<<"No Path Exists\n";
    else cout<<x.second<<"\n";
  }
  return 0;
}