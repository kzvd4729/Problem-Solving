/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/26/2018 15:40                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 748 ms                                          memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/996/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const double R=1.5e6;
int n,pos[N+2],con,nn;
struct point
{
  double x,y;
}p[N+2];
double mag(point pp)
{
  return sqrt(pp.x*pp.x+pp.y*pp.y);
}
void dfs(int msk,int cnt,point pp)
{
  if(cnt>nn)
  {
    point ppp=pp;
    for(int i=1;i<=nn;i++)
    {
      int tp=msk&(1<<i);
      if(tp)
      {
        ppp.x+=p[con+i].x,ppp.y+=p[con+i].y;
        pos[con+i]=1;
      }
      else
      {
        ppp.x-=p[con+i].x,ppp.y-=p[con+i].y;
        pos[con+i]=-1;
      }
    }
    if(mag(ppp)<=R)
    {
      for(int i=1;i<=n;i++)cout<<pos[i]<<" ";
      cout<<endl;
      exit(0);
    }
    return ;
  }
  dfs(msk,cnt+1,pp);
  dfs(msk|(1<<cnt),cnt+1,pp);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i].x>>p[i].y;
  point pp={0,0},tm1,tm2;
  for(int i=1;i<=n-3;i++)
  {
    tm1={pp.x+p[i].x,pp.y+p[i].y};
    tm2={pp.x-p[i].x,pp.y-p[i].y};
    if(mag(tm1)<=mag(tm2))
    {
      pp=tm1;
      pos[i]=1;
    }
    else
    {
      pp=tm2;
      pos[i]=-1;
    }
  }
  con=max(0,n-3);
  nn=n-con;
    dfs(0,1,pp);
   return 0;
}