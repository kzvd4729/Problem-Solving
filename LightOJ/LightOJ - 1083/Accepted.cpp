/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-14 15:29:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 376                                        memory_used (MB): 4.4                             
*  problem: https://vjudge.net/problem/LightOJ-1083
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e4,inf=1e9;

int sp[N+2][17+2],aa[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=aa[i];//array
  for(int j=1;j<=17;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    build(n);int ans=0;

    for(int i=1;i<=n;i++)
    {
      int lo=i,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(get(i,md)<aa[i])hi=md;else lo=md;
      }
      for(md=hi; ;md--)if(get(i,md)==aa[i])break;

      int rt=md;

      lo=1,hi=i,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(get(md,i)<aa[i])lo=md;else hi=md;
      }
      for(md=lo; ;md++)if(get(md,i)==aa[i])break;

      int lt=md;

      ans=max(ans,(rt-lt+1)*aa[i]);
    }
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}