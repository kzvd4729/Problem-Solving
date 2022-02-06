/****************************************************************************************
*  @author: kzvd4729                                         created: May/12/2019 22:34                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 93900 KB                             
*  problem: https://codeforces.com/contest/1158/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
//////////////////////////////////////////
int sp_min[N+2][21],SP[N+2],ans[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)
    sp_min[i][0]=SP[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp_min[i][j]=sp_min[i][j-1];
      if((i+(1<<(j-1)))>n)continue;
      sp_min[i][j]=max(sp_min[i][j-1],sp_min[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp_min[lt][dg],sp_min[rt-(1<<dg)+1][dg]);
}
//////////////////////////////////////////////
int f=0;
void dfs(int low,int hgi,int lt,int rt)
{
  //cout<<low<<" "<<hgi<<" "<<lt<<" "<<rt<<endl;
  if(low>hgi)return ;
  if(get(low,hgi)>hgi+1)f=1;
  int lo=low,hi=hgi,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(get(low,md)>hgi)hi=md;
    else lo=md;
  }
  for(md=hi;md>=lo;md--)
    if(get(low,md)>hgi)break;
  if(aa[md]<=hgi)md=hgi;
  ans[md]=rt;
  dfs(low,md-1,lt,lt+(md-low-1));
  dfs(md+1,hgi,rt-(hgi-md),rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];SP[i]=aa[i];
    }
    build(n);
     dfs(1,n,1,n);
    if(f)
    {
      cout<<-1<<endl;continue;
    }
     for(int i=1;i<=n;i++)
      cout<<ans[i]<<" ";
    cout<<endl;
     for(int i=1;i<=n;i++)
      SP[i]=0;
    for(int j=0;j<=20;j++)
      for(int i=1;i<=n;i++)
        sp_min[i][j]=0;
  }
  return 0;
}