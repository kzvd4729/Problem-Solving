/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 22:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/875/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int sp[N+2][20+2],ro[N+2][20+2],aa[N+2],n;
long ans;
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=aa[i],ro[i][0]=aa[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];ro[i][j]=ro[i][j-1];
      if((i+(1<<(j-1)))<=n)
      {
        sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        ro[i][j]=ro[i][j-1]|ro[i+(1<<(j-1))][j-1];
      }
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int ret(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return ro[lt][dg]|ro[rt-(1<<dg)+1][dg];
}
void solve(int lt,int rt)
{
  if(lt>rt)return ;
  int mx=get(lt,rt),lo=lt,hi=rt,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(get(lt,md)==mx)hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(get(lt,md)==mx)break;
  int id=md;
   lo=id,hi=rt;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ret(id,md)==mx)lo=md;else hi=md;
  }
  for(md=lo;md<=hi;md++)
    if(ret(id,md)!=mx)break;
   int nw=md;
  ans+=1LL*(id-lt+1)*(rt-md+1);
   lo=lt,hi=id;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ret(md,id)==mx)hi=md;else lo=md;
  }
  for(md=hi;md>=lo;md--)
    if(ret(md,id)!=mx)break;
  ans+=1LL*(md-lt+1)*(rt-id+1);
   ans-=1LL*(md-lt+1)*(rt-nw+1);
  solve(lt,id-1);solve(id+1,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  build(n);solve(1,n);
  cout<<ans<<endl;
  return 0;
}