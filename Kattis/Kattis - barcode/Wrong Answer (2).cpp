/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 20:07:07                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-barcode
****************************************************************************************/
/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define pf          printf
#define sf          scanf
#define ff          first
#define ss          second
#define clr         clear()
#define sz          size()
#define pb          push_back
#define mk          make_pair
#define pi          acos(-1)
//#define inf         2000000000000000000
#define mod         1000000007
#define ull         unsigned long long int
#define f(i,k,n)    for(i=k;i<n;i++)
#define fr(i,n,k)   for(i=n;i>=k;i--)
#define ent(a)      scanf("%lld",&a)
#define ent2(a,b)   scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a)      memset(a,0,sizeof(a))
#define vec(v,s)    vector<ll>v[s]
#define arr(a,s)    ll a[s];
#define bitone(x)   __builtin_popcount(x)
//#define check(n,pos) (n&(1<<pos))
//#define set(n,pos)  (n|(1<<pos))
//knight and king//
int dr[]= {2,2,-2,-2,1,-1,1,-1};
int dc[]= {1,-1,1,-1,2,2,-2,-2};
int dr1[]= {0,0,1,1,1,-1,-1,-1};
int dc1[]= {1,-1,1,0,-1,0,1,-1};
int dr2[]= {0,0,1,-1};
int dc2[]= {1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 2005

const int N=2e6,inf=1e9;
int m,dp[N+2][4];
int big(int b,int p)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init(int n)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%m;
}
int ncr(int n,int r)
{
  int a=fac[n];a=(1LL*a*big(fac[r],m-2))%m;
  return (1LL*a*big(fac[n-r],m-2))%m;
}
int dfs(int n,int f)
{
  dp[0][0]=1;dp[0][1]=1;
  for(int i=1;i<=n;i++)
  {
    dp[i][1]=dp[i-1][0];
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%m;
  }
  return dp[n][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>m;init(N);
    int ans=dfs(n,0)%m;
    if(n%2==0)
    {
      ans=(ans+ncr(n,n/2))%m;
      ans=(ans-2+m)%m;ans=(ans+m)%m;
    }
    cout<<ans<<"\n";
  }
  return 0;
}