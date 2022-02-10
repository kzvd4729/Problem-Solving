/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-07 03:09:47                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GCDMAT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N=1e5,inf=1e9,mod=1e9+7;
int vis[N+2],id,aa[N+2],mt[200+2][N+2];long mb[N+2];
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
inline int cal(int a,int b,int d)
{
  //if(a>b)return 0;
  return b/d-(a-1)/d;
}
long ret(int A,int B,int C,int D)
{
  long ans=0;int n=min(C,D);
  for(int k=1;k<=n;k++)
  {
    int a=(A+k-1)/k,c=C/k,b=(B+k-1)/k,e=D/k;
    int mn=min(c,e);int na=a-1,nb=b-1;

    int d=1;int rmn=min(mn,200);
    for( ;aa[d]<=rmn;d++)
    {
      ans+=mb[aa[d]]*k*(mt[aa[d]][c]-mt[aa[d]][na])*(mt[aa[d]][e]-mt[aa[d]][nb]);  
    }
    for( ;aa[d]<=mn;d++)
    {
      ans+=mb[aa[d]]*k*(c/aa[d]-na/aa[d])*(e/aa[d]-nb/aa[d]);
    }
  }
  return ans;
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  mobius();int t;scanf("%d",&t);int n,m;scanf("%d%d",&n,&m);
  for(int d=1;d<=200;d++)
  {
    for(int i=1;i<=N;i++)
      mt[d][i]=i/d;
  }
  while(t--)
  {
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);

    // a=1+rng()%n,c=1+rng()%n;
    // b=1+rng()%m,d=1+rng()%m;

    if(a>c)swap(a,c);if(b>d)swap(b,d);

    long area=(1LL*(c-a)*(d-b));

    if(area<=5000)
    {
      sml(a,b,c,d);continue;
    }

    long ans=ret(a,b,c,d);
    // ans-=ret(min(a-1,d),max(a-1,d));
    // ans-=ret(min(c,b-1),max(c,b-1));
    // ans+=ret(min(a-1,b-1),max(a-1,b-1));

    ans%=mod;
    printf("%lld\n",ans);
  }
  return 0;
}