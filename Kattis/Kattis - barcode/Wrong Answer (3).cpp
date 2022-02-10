/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 18:52:02                      
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
#define inf         2000000000000000000
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
ll a[1000004];
int main()
{
  ll tc,n,m,i,j;
  cin>>tc;
  while(tc--)
  {
    cin>>n>>m;
    a[0]=1;
    a[1]=2;
    for(i=2;i<=n;i++)
    {
      a[i]=(a[i-1]+a[i-2])%m;
    }
    cout<<a[n]<<endl;
  }
  return 0;
}