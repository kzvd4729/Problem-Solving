/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 20400 KB                             
*  problem: https://codeforces.com/contest/1156/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n,sp[N+2][22],lt[N+2],rt[N+2],po[N+2];
void build(void)
{
  for(int i=1;i<=n;i++)sp[i][0]=aa[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(i+(1<<(j-1))<=n)
        sp[i][j]=max(sp[i][j],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],po[aa[i]]=i;;
  build();int ans=0;
  for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(i,md)>aa[i])hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
      if(get(i,md)<=aa[i])break;
    rt[i]=md;
     lo=1,hi=i,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(get(md,i)>aa[i])lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
      if(get(md,i)<=aa[i])break;
    lt[i]=md;
  }
  for(int i=1;i<=n;i++)
  {
    if(i-lt[i]<=rt[i]-i)
    {
      for(int j=lt[i];j<=i;j++)
        if(po[aa[i]-aa[j]]>=i&&po[aa[i]-aa[j]]<=rt[i])
          ans++;
    }
    else
    {
      for(int j=i;j<=rt[i];j++)
        if(po[aa[i]-aa[j]]>=lt[i]&&po[aa[i]-aa[j]]<=i)
          ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}