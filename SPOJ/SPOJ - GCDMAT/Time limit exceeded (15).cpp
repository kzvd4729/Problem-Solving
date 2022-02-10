/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-06 23:45:59                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GCDMAT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9,mod=1e9+7;
int mb[N+2],vis[N+2],id,aa[N+2];
void mobius()
{
  for(int i=1;i<=N;i++)mb[i]=1;
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      mb[j]*=-1;vis[j]=1;

      if(i<10000&&(j%(i*i)==0))mb[j]=0;
    }
  }
  for(int i=1;i<=N;i++)
    if(mb[i]!=0)aa[++id]=i;
}
map<pair<int,int>,long>mp;
long ret(int n,int m)
{
  if(n<1)return 0;
  //if(mp.find({n,m})!=mp.end())return mp[{n,m}];
  long ans=0;
  for(int k=1;k<=n;k++)
  {
    for(int d=1,r=n/k;aa[d]<=r;d++)
    {
      //int a=n/k,b=m/k;
      int dd=aa[d];
      ans+=1LL*k*mb[dd]*(n/(k*dd))*(m/(k*dd));
    }
  }
  return ans;
  //return mp[{n,m}]=ans;
}
void sml(int a,int b,int c,int d)
{
  long ans=0;
  for(int i=a;i<=c;i++)
  {
    for(int j=b;j<=d;j++)
      ans+=__gcd(i,j);
  }
  ans%=mod;
  printf("%lld\n",ans);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  mobius();int t;scanf("%d",&t);int n,m;scanf("%d%d",&n,&m);
  while(t--)
  {
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);

    long area=(1LL*(c-a)*(d-b));

    if(area<=500)
    {
      sml(a,b,c,d);continue;
    }

    long ans=ret(min(c,d),max(c,d));
    ans-=ret(min(a-1,d),max(a-1,d));
    ans-=ret(min(c,b-1),max(c,b-1));
    ans+=ret(min(a-1,b-1),max(a-1,b-1));

    ans%=mod;
    printf("%lld\n",ans);
  }
  return 0;
}